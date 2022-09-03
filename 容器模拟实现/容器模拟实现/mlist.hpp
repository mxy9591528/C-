#pragma once
#include<iostream>
using namespace std;
namespace mxylist
{
	template<typename T>
	struct ListNode
	{
		ListNode<T>*_prev;
		ListNode<T>*_next;
		T _data;
	};
	template<typename T, typename Ref, typename Ptr>
	class ListIterator
	{
	public:
		ListNode<T>*_node;
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr> self;
		ListIterator(Node*node)
		{
			this->_node = node;
		}
		Ref operator*()
		{
			return this->_node->_data;
		}
		Ptr &operator->()
		{
			return &(this->_node->_data);
		}
		self&operator++()
		{
			this->_node = this->_node->_next;
			return *this;
		}
		self&operator++(int)
		{
			self temp(*this);
			this->_node = this->_node->_next;
			return temp;
		}
		self&operator--()
		{
			this->_node = this->_node->_prev;
			return *this;
		}
		self&operator--(int)
		{
			self temp(*this);
			this->_node = this->_node->_prev;
			return temp;
		}
		bool operator!=(const self&it)
		{
			return this->_node != it._node;
		}
		bool operator==(const self&it)
		{
			return this->_node == it._node;
		}
	};
	template<typename T>
	class mlist
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
	private:
		Node*_head;
		void CreatHead()
		{
			this->_head = new Node;
			this->_head->_prev = this->_head->_next = this->_head;
		}
	public:
		mlist();								//Ĭ�Ϲ���
		mlist(iterator begin, iterator end);	//���캯����[begin��end]�����е�Ԫ�ؿ���������
		mlist(size_t n, const T&elmn);			//���캯����n��elmn����������
		mlist(mlist<T>&list);				//�������캯��
		void assign(iterator begin, iterator end);//��[begin��end]�����е�Ԫ�ؿ���������
		void assign(size_t n, const T&elmn);	//��n��elmn����������
		mlist&operator=(mlist<T>&list);		//����=
		void swap(mlist<T>&list);						//��list��Ԫ���뱾���Ԫ�ؽ��л���
		size_t size();								//��������Ԫ�ظ���
		bool empty();								//�ж������Ƿ�Ϊ��
		void resize(size_t n, const T&elmn = 0);		//����ָ���������ȣ������Ĭ��ָ����ֵ��䣬��̣�ɾ������Ԫ��
		void push_back(const T&elmn);				//������β������һ��Ԫ��
		void pop_back();							//ɾ�����������һ��Ԫ��
		void push_front(const T&elmn);				//��ͷ������һ��Ԫ��
		void pop_front();							//ɾ��������ͷ��һ��Ԫ��
		iterator insert(iterator pos, const T&elmn);	//��pos������elmnԪ�أ����������ݵ�λ��
		void insert(iterator pos, size_t n, const T&elmn);//��pos������n��elmnԪ�أ��޷���ֵ
		void insert(iterator pos, iterator begin, iterator end);//��posλ�ò���[begin��end]��������ݣ��޷���ֵ
		void clear();							//�����������
		iterator erase(iterator begin, iterator end);//ɾ��[begin��end]��������ݣ�������һ�����ݵ�λ��
		iterator erase(iterator pos);					//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
		void remove(const T&elmn);					//ɾ��������������elmnƥ���Ԫ��
		T&front();
		T&back();
		const T&front()const;						//���ص�һ��Ԫ��
		const T&back()const;						//�������һ��Ԫ��
		void reverse();								//��ת����
		void sort();								//��������
		iterator begin();							//������
		iterator end();
		const_iterator begin()const;
		const_iterator end()const;
		~mlist();									//��������
	};
	template<typename T>
	mlist<T>::mlist()
	{
		this->CreatHead();
	}
	template<typename T>
	mlist<T>::mlist(iterator begin, iterator end)
	{
		this->CreatHead();
		while (begin != end)
		{
			this->push_back(*begin);
			++begin;
		}
	}
	template<typename T>
	mlist<T>::mlist(size_t n, const T & elmn)
	{
		this->CreatHead();
		for (size_t i = 0; i < n; i++)
			this->push_back(elmn);
	}
	template<typename T>
	mlist<T>::mlist(mlist<T> & list)
	{
		this->CreatHead();
		this->assign(list.begin(), list.end());
	}
	template<typename T>
	void mlist<T>::assign(iterator begin, iterator end)
	{
		this->CreatHead();
		this->insert(this->begin(), begin, end);
	}
	template<typename T>
	void mlist<T>::assign(size_t n, const T & elmn)
	{
		this->CreatHead();
		for (size_t i = 0; i < n; i++)
			this->push_back(elmn);
	}
	template<typename T>
	mlist<T> & mlist<T>::operator=(mlist<T> & list)
	{
		this->CreatHead();
		this->assign(list.begin(),list.end());
		return*this;
	}
	template<typename T>
	void mlist<T>::swap(mlist<T> & list)
	{
		std::swap(this->_head, list._head);
	}
	template<typename T>
	size_t mlist<T>::size()
	{
		size_t count = 0;
		for (mlist<T>::iterator it = this->begin(); it != this->end(); it++)
			count++;
		return count;
	}
	template<typename T>
	bool mlist<T>::empty()
	{
		return this->begin() == this->end();
	}
	template<typename T>
	void mlist<T>::resize(size_t n, const T & elmn)
	{
		size_t len = this->size();
		if (n <= len)
		{
			for (size_t i = n; i < len; i++)
				this->pop_back();
		}
		else
			this->insert(this->end(), n - len, elmn);
	}
	template<typename T>
	void mlist<T>::push_back(const T & elmn)
	{
		insert(this->end(), elmn);
	}
	template<typename T>
	void mlist<T>::pop_back()
	{
		this->erase(--this->end());
	}
	template<typename T>
	void mlist<T>::push_front(const T & elmn)
	{
		this->insert(this->begin(), elmn);
	}
	template<typename T>
	void mlist<T>::pop_front()
	{
		this->erase(this->begin());
	}

	template<typename T>
	typename mlist<T>::iterator mlist<T>::insert(iterator pos, const T & elmn)
	{
		Node*node = new Node, *Pos = pos._node;
		node->_data = elmn;
		node->_next = Pos;
		node->_prev = Pos->_prev;
		Pos->_prev->_next = node;
		Pos->_prev = node;
		return iterator(node);
	}

	template<typename T>
	void mlist<T>::insert(iterator pos, size_t n, const T & elmn)
	{
		while (n--)
		{
			this->insert(pos, elmn);
		}
	}

	template<typename T>
	void mlist<T>::insert(iterator pos, iterator begin, iterator end)
	{
		while (begin != end)
		{
			this->insert(pos, begin._node->_data);
			begin++;
		}
	}

	template<typename T>
	void mlist<T>::clear()
	{
		this->erase(this->begin(), this->end());
	}

	template<typename T>
	typename mlist<T>::iterator mlist<T>::erase(iterator begin, iterator end)
	{
		iterator it = begin;
		while (it != end)
		{
			it = this->erase(it);
		}
		return it;
	}

	template<typename T>
	typename mlist<T>::iterator mlist<T>::erase(iterator pos)
	{
		Node*Pos = pos._node;
		if (pos == this->end())
			return this->end();
		Node*node = Pos->_next;
		Pos->_prev->_next = node;
		node->_prev = Pos->_prev;
		delete Pos;
		Pos = NULL;
		return iterator(node);
	}

	template<typename T>
	void mlist<T>::remove(const T & elmn)
	{
		for (mlist<T>::iterator i = this->begin(); i != this->end(); i++)
		{
			if (i._node->_data == elmn)
				i=this->erase(i);
		}
	}

	template<typename T>
	T & mlist<T>::front()
	{
		return this->begin()._node->_data;
	}

	template<typename T>
	T & mlist<T>::back()
	{
		return (--this->end())._node->_data;
	}

	template<typename T>
	const T & mlist<T>::front() const
	{
		return this->begin()._node->_data;
	}

	template<typename T>
	const T & mlist<T>::back() const
	{
		return this->end()._node->_data;
	}

	template<typename T>
	void mlist<T>::reverse()
	{
		iterator begin = this->begin();
		iterator end = --this->end();
		while (begin!=end)
		{
			std::swap(begin._node->_data, end._node->_data);
			++begin;
			if (begin == end)
				return;
			--end;
			if (begin == end)
				return;
		}
	}

	template<typename T>
	void mlist<T>::sort()
	{
		for (iterator i = this->begin(); i != this->end(); i++)
		{
			iterator min = i, ret = i;
			for (iterator j =ret++; j != this->end(); j++)
				if (min._node->_data > j._node->_data)
					min = j;
			if (min != i)
				std::swap(min._node->_data, i._node->_data);
		}
	}
	template<typename T>
	typename mlist<T>::iterator mlist<T>::begin()
	{
		return iterator(this->_head->_next);
	}
	template<typename T>
	typename mlist<T>::iterator mlist<T>::end()
	{
		return iterator(this->_head);
	}
	template<typename T>
	typename mlist<T>::const_iterator mlist<T>::begin() const
	{
		return const_iterator(this->_head->_next);
	}
	template<typename T>
	typename mlist<T>::const_iterator mlist<T>::end() const
	{
		return const_iterator(this->_head);
	}
	template<typename T>
	mlist<T>::~mlist()
	{
		this->clear();
		delete this->_head;
		this->_head = NULL;
	}
}