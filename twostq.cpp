#include <stack>
#include <iostream>

template <class T>
class TwoStackQueue
{
private:
	std::stack<T> pos, pus;
public:
	TwoStackQueue() {}
	~TwoStackQueue() {}

	void push(const T& v)
	{
		pus.push(v);
	}

	T pop()
	{
		if( ! pos.empty() )
			this->migrate();
		if( ! pos.empty() )
		{
			T v = pos.top();
			pos.pop();
			return v;
		}
		return -9999;
	}

	size_t size() const
	{
		return pus.size()+pos.size();
	}

protected:
	void migrate()
	{
		if( pus.empty() )
			return;
		for(T v = pus.top(); ! pus.empty(); v = pus.top())
		{
			pos.push(v);
			pus.pop();
		}	
	}
};


int main(int, char**)
{
	TwoStackQueue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	std::cout << "Q-size=" << q.size() << std::endl;
	int v = q.pop();
	std::cout << "Q-size=" << q.size() << " v=" << v << std::endl;

	// std::cout << "Q: ";
	// for ( int v : q )
	// {
	// 	std::cout << v << " ";
	// }
	// std::cout << std::endl;

}

