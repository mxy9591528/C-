#pragma once
#include<iostream>
using namespace std;
namespace mxyvector
{
	template<typename T>
	class mvector
	{
		T*_start;
		T*_end;//��ָ���¼����Ԫ�ظ�������ȥ_start��ΪԪ�ظ���
		T*_endofstorage;//��¼����
	public:
		typedef T* iterator;//��ʹ��ģ�壬���붨��������
		typedef const T* const_iterator;
		mvector();	//����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
		mvector(T*begin, T*end);	//��v[begin(),ens()]�����Ԫ�ؿ���������
		mvector(size_t n, T elmn);	//���캯����n��elem����������
		mvector(const mvector&mvec);	//�������캯��
		mvector&operator=(const mvector&mvec); //����=��
		void assign(T* begin, T* end);	//��[begin,end]�����е����ݿ������Ƹ�����
		void assign(size_t n, T elmn);	//��n��elem����������
		bool empty();	//�ж������Ƿ�Ϊ��
		size_t capacity()const;	//��������
		size_t size()const;	//������Ԫ�صĸ���
		void resize(size_t num);	//����ָ�������ĳ���Ϊnum,�䳤��Ĭ��ֵ�����λ�ã����ɾ������Ԫ��
		void resize(size_t num, T elmn);	//����ָ�������ĳ���Ϊnum,�䳤��elmn�����λ�ã����ɾ������Ԫ��
		void push_back(T elmn);	//β��һ��Ԫ��
		void pop_back();	//βɾһ��Ԫ��
		void insert(const_iterator pos, T elmn);	//������ָ��λ��pos����Ԫ��elmn
		void insert(iterator pos, size_t count, T elmn);	//������ָ��λ��pos����count��Ԫ��elmn
		void erase(iterator pos);	//ɾ��������ָ���Ԫ��
		void erase(iterator begin, iterator end);	//ɾ����������begin��end֮���Ԫ��
		void clear();	//ɾ������������Ԫ��
		T&at(size_t index);	//��������index��ָ������
		T&operator[](size_t index);	//��������index��ָ������
		T&front();	//���������еĵ�һ��Ԫ��
		T&back();	//���������е����һ������Ԫ��
		void swap(mvector&mvec);	//��mvec�뱾���Ԫ�ػ���
		void reserve(size_t len);	//����Ԥ��len��Ԫ�س���,Ԥ��λ�ò���ʼ��,Ԫ�ز��ɷ���
		iterator&begin()
		{
			return this->_start;
		}
		iterator&end()
		{
			return this->_end;
		}
		const_iterator&begin()const
		{
			return this->_start;
		}
		const_iterator&end()const
		{
			this->_end;
		}
		~mvector();	//��������
	}; 
	template<typename T>
	mvector<T>::mvector()
	{
		this->_start = this->_end = this->_endofstorage = NULL;
	}
	template<typename T>
	mvector<T>::mvector(T*begin, T*end)
	{
		size_t len = end - begin;//��������Ŀռ䳤��
		this->reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			this->_start[i] = begin[i];
			this->_end++;
		}
	}
	template<typename T>
	mvector<T>::mvector(size_t n, T elmn)
	{
		this->reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			this->_start[i] = elmn;
			this->_end++;
		}
	}
	template<typename T>
	mvector<T>::mvector(const mvector & mvec)
	{
		this->reserve(mvec.capacity());
		for (size_t i = 0; i < mvec.size(); i++)
		{
			this->_start[i] = mvec._start[i];
			this->_end++;
		}
	}
	template<typename T>
	mvector<T>&mvector<T>::operator=(const mvector & mvec)
	{
		this->reserve(mvec.capacity());
		for (size_t i = 0; i < mvec.size(); i++)
		{
			this->_start[i] = mvec._start[i];
			this->_end++;
		}
		return *this;
	}
	template<typename T>
	void mvector<T>::assign(T*begin, T* end)
	{
		this->clear();//�����ԭ������
		size_t len = end - begin;
		this->reserve(len);
		for (size_t i = 0; i < len; i++)
		{
			this->_start[i] = begin[i];
			this->_end++;
		}
	}
	template<typename T>
	void mvector<T>::assign(size_t n, T elmn)
	{
		this->clear();
		this->reserve(n);
		for (size_t i = 0; i < n; i++)
		{
			this->_start[i] = elmn;
			this->_end++;
		}
	}
	template<typename T>
	bool mvector<T>::empty()
	{
		return this->_start == this->_end;//���ͷβָ����ͬ����δ���κ�Ԫ�أ�Ϊ��
	}
	template<typename T>
	size_t mvector<T>::capacity()const
	{
		return this->_endofstorage - this->_start;//��ַ���
	}
	template<typename T>
	size_t mvector<T>::size()const
	{
		return this->_end - this->_start;
	}
	template<typename T>
	void mvector<T>::resize(size_t num)
	{
		if (num <= this->size())//ָ�������С�ռ�
		{
			this->_end = this->_start + num;//����ָ��βָ��
			this->_endofstorage = this->_start + num;
			return;
		}
		if (num > this->capacity())//���󿪱ٿռ�
			this->reserve(num);
	}
	template<typename T>
	void mvector<T>::resize(size_t num, T elmn)//����Ӹ���ʼ����ֵ
	{
		if (num <= this->size())
		{
			this->_end = this->_start + num;
			this->_endofstorage = this->_start + num;
			return;
		}
		if (num > this->capacity())
		{
			size_t len = this->size();
			this->reserve(num);
			for (size_t i = len; i < num; i++)
			{
				this->_start[i] = elmn;
				this->_end++;
			}
		}
	}
	template<typename T>
	void mvector<T>::push_back(T elmn)
	{
		this->reserve(this->size()+1);
		this->_start[this->size()] = elmn;
		this->_end++;
	}
	template<typename T>
	void mvector<T>::pop_back()
	{
		this->_end -= 1;//βָ�����һλ����
	}
	template<typename T>
	void mvector<T>::insert(const_iterator pos, T elmn)
	{
		this->reserve(this->size()+ 1);//���ռ��Ƿ��㹻��
		T* end = this->_end- 1;//ָ�����һ��Ԫ��
		while (end >= pos)
		{
			*(end + 1) = *end;//��λ����
			end--;
		}
		*(end+1) = elmn;//����Ԫ��
		this->_end++;
	}
	template<typename T>
	void mvector<T>::insert(iterator pos, size_t count, T elmn)
	{
		size_t len1 = pos - this->_start, len2 = this->size();
		this->reserve(this->size() + count);
		pos = this->_start+len1;//pos��ַ���ܻ��������ݸı䣬��Ҫ���¸�ֵ
		for(size_t i=0;i<count;i++)
		{
			for (size_t j = 0; j < len2; j++)
				this->_end[i-j] = this->_end[i-j-1];//ѭ����λ
			pos[i] = elmn;//��Ų�����Ŀռ丳ֵ
		}
		this->_end += count;
	}
	template<typename T>
	void mvector<T>::erase(iterator pos)
	{
		for (iterator i = pos; i < this->_end - 1; i++)//��λ�������
			*i = *(i + 1);
		this->_end -= 1;
	}
	template<typename T>
	void mvector<T>::erase(iterator begin, iterator end)
	{
		size_t len = end - begin;
		for (iterator i = begin; i < end; i++)
			*i = *(i + len);
		this->_end -= len;
	}
	template<typename T>
	void mvector<T>::clear()
	{
		this->erase(this->begin(), this->_end);
	}
	template<typename T>
	T&mvector<T>::at(size_t index)
	{
		return *(this->_start + index);
	}
	template<typename T>
	T&mvector<T>::operator[](size_t index)
	{
		return *(this->_start + index);
	}
	template<typename T>
	T&mvector<T>::front()
	{
		return *this->_start;
	}
	template<typename T>
	T&mvector<T>::back()
	{
		return *(this->_end-1);//�������һ��Ԫ��
	}
	template<typename T>
	void mvector<T>::swap(mvector & mvec)
	{
		std::swap(this->_start, mvec._start);//���ÿ⺯������
		std::swap(this->_end, mvec._end);
		std::swap(this->_endofstorage, mvec._endofstorage);
	}
	template<typename T>
	void mvector<T>::reserve(size_t len)
	{
		if (len >this->capacity())
		{
			size_t sz = this->size();
			T* tmp = new T[len];
			if (this->_start) 
			{
				for (size_t i = 0; i < sz; i++)
					tmp[i] = this->_start[i];
				delete[] _start;
			}
			this->_start = tmp;
			this->_end = tmp + sz;
			this->_endofstorage = _start + len;
		}
	}
	template<typename T>
	mvector<T>::~mvector()
	{
		if(this->_start)
			delete[]this->_start;
		this->_start = this->_end = this->_endofstorage = NULL;
	}
}