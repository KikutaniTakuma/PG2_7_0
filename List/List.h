#pragma once

#include "Data/Data.h"
#include "DataIterator.h"
#include <assert.h>
#include <initializer_list>

template<class T>
class List {
public:
	/// <summary>
	/// �K��R���X�g���N�^
	/// </summary>
	inline List()
		:size(0)
	{
		front = new Data<T>;
		back = front;
		size++;
	}
	
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="data">���ꂽ���f�[�^(�ό�)</param>
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
	/// �f�X�g���N�^
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
	/// �e�v�f���Q��
	/// </summary>
	/// <param name="index">�Q�Ƃ������v�f�ԍ�</param>
	/// <returns>�C�ӂ̗v�f�̎Q��</returns>
	inline T& operator[](const size_t& index) const {
		Data<T>* buf = this->front;

		for (int i = 0; i < index && buf->next != nullptr; i++) {
			buf = buf->next;
		}

		assert(buf != nullptr);
		return buf->data;
	}


	/// <summary>
	/// �v�f����ύX
	/// </summary>
	/// <param name="index">�����ɕύX��������</param>
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
	/// �v�f����ɂ��ď�����
	/// </summary>
	inline void Clear() {
		while (size > 1) {
			this->PopBack();
		}
		front->data = T();
	}

	/// <summary>
	/// �v�f����Ԃ�
	/// </summary>
	/// <returns>�v�f��</returns>
	inline const size_t& Size() const {
		return size;
	}



	///
	/// �v�f�ǉ�
	/// 

	/// <summary>
	/// �O�ɗv�f�ǉ�
	/// </summary>
	/// <param name="data">�ǉ������v�f�ɓ����f�[�^</param>
	inline void PushFront(const T& data) {
		//  ��ԑO�̗v�f�̃|�C���^����
		Data<T>* buf = front;

		// ��ԑO�ɓ��I����
		buf->before = new Data<T>(data);

		// ���I���������v�f�ɑO�̃|�C���^����
		buf->before->next = buf;

		// �V���ɐ��������ŏ��̗v�f����
		front = buf->before;

		// �T�C�Y���A�b�v
		size++;
	}

	/// <summary>
	/// ����̗v�f�̎��Ƀf�[�^�V���ɐ������đ}��
	/// �v�f���𒴂��Ă����ꍇ��Ԍ��ɐ��������
	/// </summary>
	/// <param name="data">�ǉ������v�f�ɓ����f�[�^</param>
	/// <param name="index">�ǂ��̎��ɑ}�������邩</param>
	inline void Push(const T& data, const size_t& index) {
		Data<T>* buf = this->front;

		for (int i = 0; i < index && buf->next != nullptr; i++) {
			buf = buf->next;
		}

		Data<T>* p = buf->next;

		buf->next = nullptr;

		buf->next = new Data<T>(data);

		// �ǉ������v�f��before�ɑO�̗v�f�̃|�C���^����
		buf->next->before = buf;

		// �ǉ������v�f��next�Ɏ��̗v�f�̃|�C���^����
		buf->next->next = p;

		// �ǉ�����O�̗v�f�̎��̗v�f�̑O�̗v�f�̃|�C���^����
		if (p != nullptr) {
			p->before = buf->next;
		}

		size++;
	}

	/// <summary>
	/// ���ɗv�f�ǉ�
	/// </summary>
	/// <param name="num">�ǉ������v�f�ɓ����f�[�^</param>
	inline void PushBack(const T& data) {
		//  ��Ԍ��̗v�f�̃|�C���^����
		Data<T>* buf = back;

		// ��Ԍ��ɓ��I����
		buf->next = new Data<T>(data);

		// ���I���������v�f�ɑO�̃|�C���^����
		buf->next->before = buf;

		// �V���ɐ��������Ō�̗v�f����
		back = buf->next;

		// �T�C�Y���A�b�v
		size++;
	}


	///
	/// �v�f�폜
	///

	/// <summary>
	///  ��ԑO�̗v�f���폜
	/// </summary>
	/// <returns>�������v�f�̃f�[�^</returns>
	inline const T& PopFront() {
		size--;

		// �����v�f�̃f�[�^���i�[
		T data = front->data;

		// buf�Ɉ�ԑO�̈��̃|�C���^����
		Data<T>* buf = front->next;

		// ��ԑO�̗v�f���폜
		delete front;

		// �ēx�g�p�ł���悤�ɂ��邽�߃k���|�C���^����
		front = nullptr;

		// �������v�f�̈��̃|�C���^����
		front = buf;
		
		front->before = nullptr;

		// �Ō�Ɋi�[�����v�f��return
		return data;
	}

	/// <summary>
	/// ����̗v�f���폜
	/// �v�f���𒴂��Ă����ꍇ��Ԍ����폜
	/// </summary>
	/// <param name="index">���������v�f�ԍ�</param>
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

			// �����v�f�̃f�[�^���i�[
			T data = buf->data;

			// buf�̑O�̗v�f�̎��̃|�C���^��buf�̎��̗v�f�̃|�C���^�ɑ��
			if (buf->before != nullptr) {
				buf->before->next = buf->next;
			}
			// buf�̌�̗v�f�̑O�̃|�C���^��buf�̑O�̗v�f�̃|�C���^�ɑ��
			if (buf->next != nullptr) {
				buf->next->before = buf->before;
			}

			delete buf;

			// �Ō�Ɋi�[�����v�f��return
			return data;
		}
	}

	/// <summary>
	/// ���̗v�f���폜
	/// </summary>
	inline const T& PopBack() {
		size--;

		// �����v�f�̃f�[�^���i�[
		T data = back->data;

		// buf�Ɉ�Ԍ��̈�O�̃|�C���^����
		Data<T>* buf = back->before;

		// ��Ԍ��̗v�f���폜
		delete back;

		// �ēx�g�p�ł���悤�ɂ��邽�߃k���|�C���^����
		back = nullptr;

		// �������v�f�̈�O�̃|�C���^����
		back = buf;

		// �������v�f��delete�����o�O�����l�������Ă�̂Ńk���|�C���^����
		back->next = nullptr;

		// �Ō�Ɋi�[�����v�f��return
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
	/// �v�f��
	/// </summary>
	size_t size;

	/// <summary>
	/// �O������head
	/// </summary>
	Data<T>* front;

	/// <summary>
	/// �������head
	/// </summary>
	Data<T>* back;
};