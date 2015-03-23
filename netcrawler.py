# -*- coding: utf-8 -*-

import urllib2
import urllib
import re
import thread
import time
import MySQLdb

#f = open('1.txt', 'w+')

db = MySQLdb.connect(host='localhost', user='root', passwd='666', db='pyChaim_SQL', charset='utf8')
cur = db.cursor()
cur.execute("DROP TABLE msg")
sql = " CREATE TABLE msg(Page INT, Tim VARCHAR (20), Msg TEXT (10240000))"
cur.execute(sql)

#----------- 加载处理糗事百科 -----------
class Spider_Model:
    def __init__(self):
        self.page = 1
        self.pages = []
        self.enable = False

    # 将所有的段子都扣出来，添加到列表中并且返回列表
    def GetPage(self, page):
        myUrl = "http://m.qiushibaike.com/hot/page/" + page
        user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
        headers = {'User-Agent': user_agent}
        req = urllib2.Request(myUrl, headers = headers)
        myResponse = urllib2.urlopen(req)
        myPage = myResponse.read()
        #encode的作用是将unicode编码转换成其他编码的字符串
        #decode的作用是将其他编码的字符串转换成unicode编码
        unicodePage = myPage.decode("utf")
        # 找出所有class="content"的div标记
        #re.S是任意匹配模式，也就是.可以匹配换行符
        myItems = re.findall('<div.*?class="content".*?title="(.*?)">(.*?)</div>', unicodePage, re.S)
        items = []
        for item in myItems:
            # item 中第一个是div的标题，也就是时间
            # item 中第二个是div的内容，也就是内容
            items.append([item[0].replace("\n", ""), item[1].replace("\n", "")])
        return items


    # 用于加载新的内容
    def LoadPage(self):
        # 如果用户未输入q 则一直运行
        while self.enable:
            # 如果pages数组中的内容小于2个
            if len(self.pages) < 2:
                try:
                    # 获取新的页面中的内容
                    myPage = self.GetPage(str(self.page))
                    self.page += 1
                    self.pages.append(myPage)
                except:
                    print '无法链接。。。。！'
            else:
                time.sleep(1)

    # 保存和 展示
    def ShowPage(self, nowPage, page):
        for items in nowPage:
            #  f.writelines(str(line.encode('utf')))
           # f.writelines('\n')
            sql1 = ('INSERT INTO msg(Page, Tim, Msg) VALUES("%d", "%s", "%s")' % (page, items[0], items[1]))
            try:
                cur.execute(sql1)
                db.commit()
            except:
                db.rollback()
            print u'第%d页' % page, items[0], items[1]

            myInput =raw_input()
            if myInput == "q":
                self.enable = False
                db.close()
                break
    #开始
    def Start(self):
        self.enable = True
        page = self.page

        print u'正在加载中请稍候......'

        # 新建一个线程在后台加载内容并存储
        thread.start_new_thread(self.LoadPage, ()) #  调用LoadPage

        #----------- 加载 处理-----------
        while self.enable:
            # 如果self的page数组中存有元素
            if self.pages:
                nowPage = self.pages[0]
                del self.pages[0]
                self.ShowPage(nowPage, page) # 调用ShowPage
                page += 1


#----------- 程序的入口处 -----------
print u"""
---------------------------------------
   程序：网络爬虫
   版本：1
   作者：who
   日期：2015-3-21
   语言：Python 2.79
   操作：输入 q 退出阅读
   功能：按下回车依次浏览今日的热点
---------------------------------------
"""


print u'请按下回车浏览今日的内容：'
raw_input(' ')
myModel = Spider_Model()
myModel.Start()
