#pragma once

#include "Data/Data.h"
#include "DataIterator.h"
#include <assert.h>
#include <initializer_list>

template<class T>
class List {
public:
	/// <summary>
	/// 規定コンストラクタ
	/// </summary>
	inline List()
		:size(0)
	{
		front = new Data<T>;
		back = front;
		size++;
	}
	
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="data">入れたいデータ(可変個)</param>
	inline List(std::initializer_list<T> data)
		:size(0)
	{
		for (auto&& i : data) {
			if (size == 0) {
				front = new Data<T>(i);
				back = front;
				size++;
			}
			else {
				this->PushBack(i);
			}
		}
	}

	/// <summary>
	/// デストラクタ
	/// </summary>
	inline ~List() {
		Data<T>* buf = front;
		Data<T>* bufNext;
		do {
			bufNext = buf->next;
			delete buf;
			buf = bufNext;
		} while (bufNext != nullptr);
	}



	/// <summary>
	/// 各要素を参照
	/// </summary>
	/// <param name="index">参照したい要素番号</param>
	/// <returns>任意の要素の参照</returns>
	inline T& operator[](const size_t& index) const {
		Data<T>* buf = this->front;

		for (int i = 0; i < index && buf->next != nullptr; i++) {
			buf = buf->next;
		}

		assert(buf != nullptr);
		return buf->data;
	}


	/// <summary>
	/// 要素数を変更
	/// </summary>
	/// <param name="index">いくつに変更したいか</param>
	inline void Resize(const size_t& index) {
		if (index == size) {
			return;
		}
		else if (index < size) {
			while (index != size) {
				this->PopBack();

				if (index == size) {
					break;
				}
			}
		}
		else if (index > size) {
			while (index != size) {
				this->PushBack(T());

				if (index == size) {
					break;
				}
			}
		}
	}

	/// <summary>
	/// 要素を一つにして初期化
	/// </summary>
	inline void Clear() {
		while (size > 1) {
			this->PopBack();
		}
		front->data = T();
	}

	/// <summary>
	/// 要素数を返す
	/// </summary>
	/// <returns>要素数</returns>
	inline const size_t& Size() const {
		return size;
	}



	///
	/// 要素追加
	/// 

	/// <summary>
	/// 前に要素追加
	/// </summary>
	/// <param name="data">追加した要素に入れるデータ</param>
	inline void PushFront(const T& data) {
		//  一番前の要素のポインタを代入
		Data<T>* buf = front;

		// 一番前に動的生成
		buf->before = new Data<T>(data);

		// 動的生成した要素に前のポインタを代入
		buf->before->next = buf;

		// 新たに生成した最初の要素を代入
		front = buf->before;

		// サイズをアップ
		size++;
	}

	/// <summary>
	/// 特定の要素の次にデータ新たに生成して挿入
	/// 要素数を超えていた場合一番後ろに生成される
	/// </summary>
	/// <param name="data">追加した要素に入れるデータ</param>
	/// <param name="index">どこの次に挿入させるか</param>
	inline void Push(const T& data, const size_t& index) {
		Data<T>* buf = this->front;

		for (int i = 0; i < index && buf->next != nullptr; i++) {
			buf = buf->next;
		}

		Data<T>* p = buf->next;

		buf->next = nullptr;

		buf->next = new Data<T>(data);

		// 追加した要素のbeforeに前の要素のポインタを代入
		buf->next->before = buf;

		// 追加した要素のnextに次の要素のポインタを代入
		buf->next->next = p;

		// 追加する前の要素の次の要素の前の要素のポインタを代入
		if (p != nullptr) {
			p->before = buf->next;
		}

		size++;
	}

	/// <summary>
	/// 後ろに要素追加
	/// </summary>
	/// <param name="num">追加した要素に入れるデータ</param>
	inline void PushBack(const T& data) {
		//  一番後ろの要素のポインタを代入
		Data<T>* buf = back;

		// 一番後ろに動的生成
		buf->next = new Data<T>(data);

		// 動的生成した要素に前のポインタを代入
		buf->next->before = buf;

		// 新たに生成した最後の要素を代入
		back = buf->next;

		// サイズをアップ
		size++;
	}


	///
	/// 要素削除
	///

	/// <summary>
	///  一番前の要素を削除
	/// </summary>
	/// <returns>消した要素のデータ</returns>
	inline const T& PopFront() {
		size--;

		// 消す要素のデータを格納
		T data = front->data;

		// bufに一番前の一つ後のポインタを代入
		Data<T>* buf = front->next;

		// 一番前の要素を削除
		delete front;

		// 再度使用できるようにするためヌルポインタを代入
		front = nullptr;

		// 消した要素の一つ後のポインタを代入
		front = buf;
		
		front->before = nullptr;

		// 最後に格納した要素をreturn
		return data;
	}

	/// <summary>
	/// 特定の要素を削除
	/// 要素数を超えていた場合一番後ろを削除
	/// </summary>
	/// <param name="index">消したい要素番号</param>
	inline const T& Pop(const size_t& index) {
		if (index >= size) {
			return this->PopBack();
		}
		else {
			size--;

			Data<T>* buf = this->front;

			for (int i = 0; i < index && buf->next != nullptr; i++) {
				buf = buf->next;
			}

			// 消す要素のデータを格納
			T data = buf->data;

			// bufの前の要素の次のポインタをbufの次の要素のポインタに代入
			if (buf->before != nullptr) {
				buf->before->next = buf->next;
			}
			// bufの後の要素の前のポインタをbufの前の要素のポインタに代入
			if (buf->next != nullptr) {
				buf->next->before = buf->before;
			}

			delete buf;

			// 最後に格納した要素をreturn
			return data;
		}
	}

	/// <summary>
	/// 後ろの要素を削除
	/// </summary>
	inline const T& PopBack() {
		size--;

		// 消す要素のデータを格納
		T data = back->data;

		// bufに一番後ろの一つ前のポインタを代入
		Data<T>* buf = back->before;

		// 一番後ろの要素を削除
		delete back;

		// 再度使用できるようにするためヌルポインタを代入
		back = nullptr;

		// 消した要素の一つ前のポインタを代入
		back = buf;

		// 消した要素のdeleteしたバグった値が入ってるのでヌルポインタを代入
		back->next = nullptr;

		// 最後に格納した要素をreturn
		return data;
	}


	inline DataItarator<T> begin() {
		return  DataItarator<T>(front);
	}

	inline  DataItarator<T> end() {
		return  DataItarator<T>(back);
	}

private:
	/// <summary>
	/// 要素数
	/// </summary>
	size_t size;

	/// <summary>
	/// 前方向のhead
	/// </summary>
	Data<T>* front;

	/// <summary>
	/// 後方向のhead
	/// </summary>
	Data<T>* back;
};