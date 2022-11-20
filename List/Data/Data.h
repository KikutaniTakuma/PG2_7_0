#pragma once

template<class T>
class Data {
public:
	inline Data() {
		before = nullptr;
		next = nullptr;
		data = T();
	}
	inline Data(T num) {
		before = nullptr;
		next = nullptr;
		data = num;
	}
	inline ~Data() {
		
	}

	inline const Data<T>& operator=(const Data<T>& num) {
		this->before = num.before;
		this->next = num.next;
		this->data = num.data;

		return *this;
	}

	Data* before;
	Data* next;
	T data;
};