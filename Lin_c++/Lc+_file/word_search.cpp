/*************************************************************************
	> File Name: word_search.cpp
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Sat 21 Mar 2015 08:36:06 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>

class Query_Base
{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base() {}
private:
	virtual std::set<line_no>
		eval(const TextQuery&) const = 0;
	virtual std::ostream&
		display(std::ostream& = std::cout) const = 0;
};

class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);
	Query(const Query &c):q(c.q), use(c.use){++*use;}
	~Query(){decr_use(); }
	Query& operator= (const Query&);
	std::srt<TextQuery::line_no>
		eval(const TextQuery &t) const {return q->eval(t);}
	std::ostream &display(std::ostream &os) const {return q->display(os);}
private:
	Query(Query_base *query): q(query), use(new std::size_t(1)){}
	Query_base *q;
	std::size_t *use;
	void decr_use()
	{if (--*use == 0){delete q; delete use;}}
};

inline Query operator~(const Query &oper)
{
	return new NotQuery(oper);
}
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}
class WordQuery: public Base_Query
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s){}
	std::set<line_no> eval(const TextQuery &t) const
		{ return t.run_query(query_word);}
	std::ostream& display(std::ostream &os) const
	{ return os << query_word;}
	std::string query_word;
};
class NotQuery : public Query_Base
{
	friend Query operator~(const Query &);
	NotQuery(Query q): query(q){}
	std::set<line_no> eval(const TextQuery&) const;
	std::ostream& display(std::ostream &os) const
	{ return os << "~(" << query << ")";}
	const Query query;
};




