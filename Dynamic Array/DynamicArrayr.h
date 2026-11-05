#pragma once

class DynamicArray
{
private:
    int* arrayData_ = nullptr;
    int arrayLength_ = 0;
public:
    DynamicArray() = default;
    DynamicArray(const int* const arrayData, const int arrayLength);
    DynamicArray(const DynamicArray& other);
    ~DynamicArray();
    int getLength() const;
    void swap(const DynamicArray& other);
    int findElement;
    void inputArray();
    void outputArray();
    void sortArray();
    bool insertByIndex(int index);
    bool deletetByIndex(int index);
    bool deleteByValue(int value);
    void deleteAllWithValue(int value);
    void begin();
    void end();
    void insertBeforeIteraror(int value);
    void deleteWithIterators();
    void move();

    DynamicArray& operator=(const DynamicArray& other);
    int& operator[](const int index);
    const int& operator[](const int index) const;
    DynamicArray operator+(const int value);
    DynamicArray operator+=(const int value);
    DynamicArray& operator=(const DynamicArray&& other);
    DynamicArray operator+(const DynamicArray& other);
    DynamicArray operator+=(const DynamicArray& other);
    bool operator==(const DynamicArray& other);
    bool operator!=(const DynamicArray& other);
};