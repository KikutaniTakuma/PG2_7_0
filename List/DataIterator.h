#pragma once

#include "Data/Data.h"

template<class T>
class DataItarator {
public:

	inline DataItarator(Data<T>* begin) {
		pos = begin;
	}

	inline T& operator*() const {
		return pos->data;
	}

	inline DataItarator<T> operator++() {
		pos = pos->next;
		return *this;
	};

	inline bool operator!=(const DataItarator<T>& ite) const {
		if (ite.pos == nullptr && pos == nullptr) {
			return true;
		}

		return this->pos != nullptr;
	}

	inline bool operator==(const DataItarator<T>& ite) const {
		if (ite.pos == nullptr && pos == nullptr) {
			return false;
		}

		return this->pos == ite.pos;
	}



	Data<T>* pos;
};