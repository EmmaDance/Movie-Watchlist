//#pragma once
//
//template <typename T>
//class DynamicVector {
//private:
//	int size;
//	int capacity;
//	T* elems;
//
//public:
//	DynamicVector() {
//		this->size = 0;
//		this->capacity = 10;
//		this->elems = new T[this->capacity];
//	}
//
//	DynamicVector(int capacity) {
//		this->size = 0;
//		this->capacity = capacity;
//		this->elems = new T[capacity];
//	}
//
//	DynamicVector(const DynamicVector& v) {
//		this->size = v.size;
//		this->capacity = v.capacity;
//		this->elems = new T[capacity];
//		for (int i = 0; i < this->size; i++) {
//			this->elems[i] = v.elems[i];
//		}
//	}
//
//	~DynamicVector() {
//		delete[] this->elems;
//	}
//
//	void resize() {
//		this->capacity *= 2;
//		T* p = new T[this->capacity];
//		for (int i = 0; i < this->size; i++) {
//			p[i] = this->elems[i];
//		}
//		delete[] this->elems;
//		this->elems = p;
//	}
//
//	T& operator[](int pos) {
//		return this->elems[pos];
//	}
//
//	bool operator-(T& e) {
//		return this->remove(e);
//	}
//
//	DynamicVector& operator=(const DynamicVector& v) {
//		this->size = v.size;
//		this->capacity = v.capacity;
//		delete[] this->elems;
//		this->elems = new T[capacity];
//		for (int i = 0; i < this->size; i++) {
//			this->elems[i] = v.elems[i];
//		}
//		return *this;
//	}
//
//	/*
//	Adds a T element to the dynamic vector
//	Input: e - the element
//	Output: true - if e was successfully added
//			false - otherwise
//	*/
//	bool add(const T& e) {
//		if (getPosition(e) > -1) {
//			return false;
//		}
//		if (this->size == this->capacity) {
//			this->resize();
//		}
//		this->size++;
//		this->elems[this->size-1] = e;
//		return true;
//	}
//	
//
//	/*
//	Removes a T element from the dynamic vector
//	Input: e - the element
//	Output: true - if e was successfully removed
//	false - otherwise
//	*/
//	bool remove(T& e) {
//		int pos = this->getPosition(e);
//		if (pos == -1) {
//			return false;
//		}
//		for (int i = pos; i < this->size-1; i++) {
//			this->elems[i] = this->elems[i + 1];
//		}
//		this->size--;
//		return true;
//	}
//
//	/*
//	Updates the information of a T element e in the dynamic vector
//	Input: e - the element
//	Output: true - if e was successfully updated
//			false - otherwise
//	*/
//	bool update(T& e) {
//		int pos = getPosition(e);
//		if (pos > -1) {
//			this->elems[pos] = e;
//			return true;
//		}
//		return false;
//	}
//
//	// Returns the size of the dynamic vector
//	int getSize() {
//		return this->size;
//	}
//
//	int setSize(int size) {
//		this->size = size;
//	}
//
//	// Returns the position of element e in the dynamic vector
//	int getPosition(const T& e) {
//		for (int i = 0; i < this->size; i++) {
//			if (this->elems[i] == e)
//				return i;
//		}
//		return -1;
//	}
//};