#pragma once

#include <iterator>
#include <exception>


namespace mydeque
{

	class exc1 : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "An attempt to access empty element";
		}
	}
	_deque_empty_entry;

	class exc2 : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "An attempt to use null iterator";
		}
	}
	_deque_null_iterator;

	class exc3 : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Invalid range";
		}
	}
	_invalid_range;

	template <typename T>
	class entry
	{
	public:
		entry() : prev(nullptr), next(nullptr), flag(true) {};

		entry(entry<T>* prev, entry<T>* next) : prev(prev), next(next), flag(true) {};

		template< class... Args >
		entry(entry<T>* prev, entry<T>* next, Args&&... args) :
			prev(prev),
			next(next),
			flag(true),
			value(std::forward<Args>(args)...) {};

		~entry()
		{
			if (next != nullptr && flag)
				delete next;
		}

		T value;
		class entry<T>* next;
		class entry<T>* prev;

		void clear()
		{
			flag = false;
			delete this;
		}

	private:
		bool flag;
	};

	template<typename T>
	class deque
	{
	public:

		/**** Iterator && his stuff ****/

		class iterator : public std::iterator<std::random_access_iterator_tag, T>
		{
		public:
			iterator() : cur(nullptr), isEnd(false) {}

			iterator(const iterator& rhs)
			{
				cur = rhs.cur;
				isEnd = rhs.isEnd;
			}

			iterator& operator = (const iterator& rhs)
			{
				cur = rhs.cur;
				isEnd = rhs.isEnd;
				return *this;
			}

			iterator& operator ++ () //prefix
			{
				if (cur)
				{
					if (cur->next)
					{
						cur = cur->next;
						isEnd = false;
					}
					else
						isEnd = true;
				}
				return *this;
			}

			iterator& operator -- () //prefix
			{
				if (cur && !isEnd)
				{
					if (cur->prev)
						cur = cur->prev;
				}
				if (isEnd)
					isEnd = false;
				return *this;
			}

			iterator operator ++ (int) //postfix
			{
				entry<T>* old_value = cur;
				++(*this);
				return iterator(old_value);
			}

			iterator operator -- (int) //postfix
			{
				entry<T>* old_value = cur;
				--(*this);
				return iterator(old_value);
			}

			iterator& operator += (int n)
			{
				if (n >= 0)
				{
					for (int i = 0; i < n; i++)
						(*this)++;
				}
				else
					(*this) -= n * (-1);

				return *this;
			}

			iterator& operator -= (int n)
			{
				if (n >= 0)
				{
					for (int i = 0; i < n; i++)
						(*this)--;
				}
				else
					(*this) += n * (-1);
				return *this;
			}

			iterator operator + (int n)
			{
				iterator it(cur, isEnd);
				it += n;
				return it;
			}

			iterator operator - (int n)
			{
				iterator it(cur, isEnd);
				it -= n;
				return it;
			}

			int operator - (iterator& rhs)
			{
				entry<T>* start;
				iterator end;
				bool sign;

				if (*this < rhs)
				{
					start = cur; end = rhs; sign = false;
				}
				else
				{
					start = rhs.cur; end = *this; sign = true;
				}

				iterator it(start);
				long count = 0;

				while (it != end && it)
				{
					++it; ++count;
				}

				return sign ? count : count * (-1);
			}

			T& operator [] (int n)
			{
				return (*(iterator(cur) += n));
			}

			T& operator * ()
			{
				if (cur && !isEnd)
					return cur->value;
				else
					throw _deque_empty_entry;
			}

			bool operator == (iterator& rhs)
			{
				return (cur == rhs.cur && isEnd == rhs.isEnd);
			}

			bool operator != (iterator& rhs)
			{
				return !(*this == rhs);
			}

			bool operator < (iterator& rhs)
			{
				if (rhs.isEnd && !isEnd)
					return true;

				if (isEnd)
					return false;


				iterator it(cur);
				++it;

				while (it != rhs && it)
					++it;
				return (it == rhs);
			}

			bool operator <= (iterator& rhs)
			{
				if (rhs.isEnd)
					return true;

				iterator it(cur);

				while (it != rhs && it)
					++it;
				return (it == rhs);
			}

			bool operator > (iterator& rhs)
			{
				if (!rhs.isEnd && isEnd)
					return true;

				if (rhs.isEnd)
					return false;


				iterator it(rhs);
				++it;

				while (it != *this && it)
					++it;
				return (it == *this);
			}

			bool operator >= (iterator& rhs)
			{
				if (isEnd)
					return true;

				iterator it(rhs);

				while (it != *this && it)
					++it;

				return (it == *this);
			}

			operator bool()
			{
				return (cur != nullptr && !isEnd);
			}

		private:
			friend class deque;
			entry<T>* cur;
			bool isEnd;

			iterator(entry<T>* cur) : cur(cur), isEnd(false) {}
			iterator(entry<T>* cur, bool isEnd) : cur(cur), isEnd(isEnd) {};

			entry<T>* getEntry()
			{
				return cur;
			}
		};

		iterator begin()
		{
			return iterator(data);
		}

		iterator end()
		{
			return iterator(last, true);
		}


		/**** Member functions ****/

		deque() : data(nullptr), last(nullptr), count(0) {}
		deque(size_t count, const T& value) : data(nullptr), last(nullptr), count(0) { assign(count, value); }
		deque(size_t count) : data(nullptr), last(nullptr), count(0) { resize(count); }
		deque(deque& other) : data(nullptr), last(nullptr), count(0)
		{
			for (iterator it = other.begin(); it != other.end(); it++)
				push_back(*it);
		}
		~deque() { if (data) delete data; }

		deque& operator=(deque& other)
		{
			for (iterator it = other.begin(); it != other.end(); it++)
				push_back(*it);

			return *this;
		}

		void assign(size_t count_t, const T& value)
		{
			size_t cur = 0; iterator it = begin();
			for (cur; cur<count && cur<count_t; cur++, it++)
				*(it) = value;

			for (cur; cur < count_t; cur++)
				emplace_back(value);
		}


		/**** Element access ****/

		T& at(size_t pos)
		{
			iterator it = begin();
			for (size_t i = 0; i < pos; i++)
				it++;

			return *it;
		}

		T& operator[] (size_t pos)
		{
			return at(pos);
		}

		T& front()
		{
			return data->value;
		}

		T& back()
		{
			return last->value;
		}


		/**** Capacity ****/

		bool empty()
		{
			return (count == 0);
		}

		size_t size()
		{
			return count;
		}


		/**** Modifiers ****/

		void clear()
		{
			delete data;
			data = nullptr;
			last = nullptr;
		}

		iterator insert(iterator pos, const T& value)
		{
			if (pos)
			{
				pos.getEntry()->prev = new entry<T>(pos.getEntry()->prev, pos.getEntry());
				iterator it = iterator(pos.getEntry()->prev);
				*it = value;

				if (it.getEntry()->prev)
					it.getEntry()->prev->next = it.getEntry();

				if (pos.getEntry() == data)
					data = pos.getEntry()->prev;

				count++;

				return it;
			}
			else
				throw _deque_null_iterator;
		}

		iterator insert(iterator pos, size_t count, const T& value)
		{
			for (size_t i = 0; i < count; i++)
				pos = insert(pos, value);
			return pos;
		}

		template<class... Args >
		iterator emplace(iterator pos, Args&&... args)
		{
			if (pos)
			{
				pos.getEntry()->prev = new entry<T>(pos.getEntry()->prev, pos.getEntry(), std::forward<Args>(args)...);
				iterator it = iterator(pos.getEntry()->prev);

				if (it.getEntry()->prev)
					it.getEntry()->prev->next = it.getEntry();

				if (pos.getEntry() == data)
					data = pos.getEntry()->prev;

				count++;

				return it;
			}
			else
				throw _deque_null_iterator;
		}

		iterator erase(iterator pos)
		{
			if (pos)
			{
				entry<T>* cur = pos.getEntry();
				entry<T>* next = cur->next;

				if (cur == data)
					data = cur->next;

				if (cur == last)
					last = cur->prev;

				if (cur->prev)
					cur->prev->next = cur->next;
				if (cur->next)
					cur->next->prev = cur->prev;

				cur->clear();
				if (next)
					return iterator(next);
				else
					return iterator(nullptr, true);
			}
			else
				throw _deque_null_iterator;
		}

		iterator erase(iterator firstIt, iterator lastIt)
		{
			if (firstIt < lastIt)
			{
				if (lastIt)
				{
					if (firstIt.getEntry() == data)
					{
						data = lastIt.getEntry();
						lastIt.getEntry()->prev = nullptr;
					}
					else
						lastIt.getEntry()->prev = firstIt.getEntry()->prev;

					for (entry<T>* cur = firstIt.getEntry(); cur != lastIt.getEntry(); )
					{
						entry<T>* next = cur->next;
						cur->clear();
						cur = next;
						count--;
					}
					return lastIt;
				}
				else
				{
					if (firstIt.getEntry() == data)
						clear();
					else
					{
						last = firstIt.getEntry()->prev;
						last->next = nullptr;
						for (entry<T>* cur = firstIt.getEntry(); cur != nullptr; )
						{
							entry<T>* next = cur->next;
							cur->clear();
							cur = next;
							count--;
						}
					}
					return iterator(nullptr, true);
				}
			}
			if (lastIt > firstIt)
				throw _invalid_range;
			else
				return iterator(lastIt.getEntry(), lastIt.isEnd);
		}

		void push_back(const  T& value)
		{
			if (data)
			{
				last->next = new entry<T>(last, nullptr);
				last = last->next;
				last->value = value;
			}
			else
			{
				data = new entry<T>();
				data->value = value;
				last = data;
			}
			count++;
		}

		template< class... Args >
		void emplace_back(Args&&... args)
		{
			if (data)
			{
				last->next = new entry<T>(last, nullptr, std::forward<Args>(args)...);
				last = last->next;
			}
			else
			{
				data = new entry<T>(nullptr, nullptr, std::forward<Args>(args)...);
				last = data;
			}
			count++;
		}

		void pop_back()
		{
			if (data)
			{
				if (last == data)
					clear();
				else
				{
					last = last->prev;
					last->next->clear();
					last->next = nullptr;
				}
				count--;
			}
		}

		void push_front(const  T& value)
		{
			if (data)
			{
				data->prev = new entry<T>(nullptr, data);
				data = data->prev;
				data->value = value;
			}
			else
			{
				data = new entry<T>();
				data->value = value;
				last = data;
			}
			count++;
		}

		template< class... Args >
		void emplace_front(Args&&... args)
		{
			if (data)
			{
				data->prev = new entry<T>(nullptr, data, std::forward<Args>(args)...);
				data = data->prev;
			}
			else
			{
				data = new entry<T>(nullptr, nullptr, std::forward<Args>(args)...);
				last = data;
			}
			count++;
		}

		void pop_front()
		{
			if (data)
			{
				if (data->next)
				{
					data = data->next;
					data->prev->clear();
					data->prev = nullptr;
				}
				else
					clear();
				count--;
			}
		}

		void resize(size_t newsize)
		{
			if (newsize >= 0)
			{
				if (count > newsize)
				{
					for (newsize; newsize < count; )
						pop_back();
				}
				else
				{
					for (newsize; newsize > count; )
						push_back(T());
				}
			}
			else
				throw _invalid_range;
		}

		void resize(size_t newsize, const T& value)
		{
			if (newsize >= 0)
			{
				if (count > newsize)
				{
					for (newsize; newsize < count; )
						pop_back();
				}
				else
				{
					for (newsize; newsize > count; )
						push_back(value);
				}
			}
			else
				throw _invalid_range;
		}

		void swap(deque& other)
		{
			size_t intbuf = count;
			count = other.count;
			other.count = intbuf;

			entry<T> *buf = data;
			data = other.data;
			other.data = buf;

			buf = last;
			last = other.last;
			other.last = buf;
		}

	private:
		entry<T>* data;
		entry<T>* last;
		size_t count;
	};

	template< class Container >
	class front_insert_iterator : public std::iterator< std::output_iterator_tag, void, void, void, void >
	{
	public:
		front_insert_iterator(Container& c) : c(c) {}
		front_insert_iterator& operator * () { return *this; }
		front_insert_iterator& operator ++ () { return *this; }
		front_insert_iterator& operator ++ (int) { return *this; }

		template<typename T>
		front_insert_iterator<Container>& operator=(const T& value)
		{
			c.push_front(value);
			return *this;
		}
	private:
		Container & c;
	};


	/**** Non-member functions ****/

	template<class T>
	void swap(deque<T> lhs, deque<T> rhs)
	{
		lhs.swap(rhs);
	}

	template< class T>
	bool operator==(deque<T>& lhs, deque<T>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return false;
		}
		return true;
	}

	template< class T>
	bool operator!=(deque<T>& lhs, deque<T>& rhs)
	{
		if (lhs.size() != rhs.size())
			return true;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return true;
		}
		return false;
	}

}
