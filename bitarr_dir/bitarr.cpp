#include ".//bitarr.hpp"
#include <iostream>
#include <cstring>


// explicit BitArray::BitArray(int _num_bits, unsigned long value = 0){

//}
// Обменивает значения двух битовых массивов. 
void BitArray::swap(BitArray &b)
{
  char *temp1 = new char[_num_bits];
  char *temp2 = new char[b._num_bits];
  for (int i = 0; i < _num_bits; i++)
  {
    temp1[i] = bitarr[i];
  }
  delete[] bitarr;
  for (int i = 0; i < b._num_bits; i++)
  {
    temp2[i] = b.bitarr[i];
  }
  delete[] b.bitarr;
  std::swap(_num_bits, b._num_bits);
  b.bitarr = temp1;
  bitarr = temp2;
  delete[] temp1;
  delete[] temp2;
}

BitArray &BitArray::operator=(const BitArray &b)
{
  _num_bits = b._num_bits;
  for (int i = 0; i < _num_bits; i++)
  {
    bitarr[i] = b.bitarr[i];
  }
  return *this;
}

// Изменяет размер массива. В случае расширения, новые элементы
// инициализируются значением value.
void BitArray::resize(int _num_bits, bool value /*= false*/)
{
  if (this->_num_bits == _num_bits)
  {
    return;
  }
  char *temp = new char[_num_bits];
  if (_num_bits < this->_num_bits)
  {
    for (int i = 0; i < _num_bits; i++)
    {
      temp[i] = bitarr[i];
    }
    delete[] bitarr;
    this->_num_bits = _num_bits;
    bitarr = temp;
    delete[] temp;
  }
  else
  {
    for (int i = 0; i < this->_num_bits; i++)
    {
      temp[i] = bitarr[i];
    }
    for (int j = this->_num_bits; j < _num_bits; j++)
    {
      temp[j] = value;
    }
    delete[] bitarr;
    this->_num_bits = _num_bits;
    bitarr = temp;
    delete[] temp;
  }
}
// Очищает массив.
void BitArray::clear()
{
  delete[] bitarr;
}

// Добавляет новый бит в конец массива. В случае необходимости
// происходит перераспределение памяти.

void BitArray::push_back(bool bit)
{
  char *temp = new char[_num_bits + 1];
  for (int i = 0; i < _num_bits; i++)
  {
    temp[i] = bitarr[i];
  }
  temp[_num_bits] = bit;
  delete[] bitarr;
  bitarr = temp;
  delete[] temp;
}

// //Битовые операции над массивами.
// //Работают только на массивах одинакового размера.
// //Обоснование реакции на параметр неверного размера входит в задачу.

BitArray &BitArray::operator&=(const BitArray &b)
{
  for (int i = 0; i < _num_bits; i++)
  {
    bitarr[i] = bitarr[i] & b.bitarr[i];
  }
  return *this;
}

BitArray &BitArray::operator|=(const BitArray &b)
{
  for (int i = 0; i < _num_bits; i++)
  {
    bitarr[i] = bitarr[i] | b.bitarr[i];
  }
  return *this;
}
BitArray &BitArray::operator^=(const BitArray &b)
{
  for (int i = 0; i < _num_bits; i++)
  {
    bitarr[i] = bitarr[i] ^ b.bitarr[i];
  }
  return *this;
}

// Битовый сдвиг с заполнением нулями.

BitArray &BitArray::operator<<=(int n)
{
  for (int i = 0; i < n; i++)
  {
    bitarr[i] <<= 1;
  }
  return *this;
}
BitArray &BitArray::operator>>=(int n)
{
  for (int i = 0; i < n; i++)
  {
    bitarr[i] >>= 1;
  }
  return *this;
}
BitArray BitArray::operator<<(int n) const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < n; i++)
  {
    temp.bitarr[i] = bitarr[i] << 1;
  }
  return temp;
}
BitArray BitArray::operator>>(int n) const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < n; i++)
  {
    temp.bitarr[i] = bitarr[i] >> 1;
  }
  return temp;
}

// Устанавливает бит с индексом n в значение val.
BitArray &BitArray::set(int n, bool val /*= true*/)
{
  if (n > _num_bits)
  {
    std::cout << "index >= than array size"
              << "\n";
  }
  else
  {
    bitarr[n] = val;
  }
  return *this;
}
// Заполняет массив истиной.
BitArray &BitArray::set()
{
  for (int i = 0; i < this->_num_bits; i++)
  {
    bitarr[i] = true;
  }
  return *this;
}

// Устанавливает бит с индексом n в значение false.
BitArray &BitArray::reset(int n)
{
  if (n > this->_num_bits)
  {
    std::cout << "index >= than array size"
              << "\n";
  }
  else
  {
    this->bitarr[n] = false;
  }
  return *this;
}

// Заполняет массив ложью.
BitArray &BitArray::reset()
{
  for (int i = 0; i < this->_num_bits; i++)
  {
    this->bitarr[i] = false;
  }
  return *this;
}

// true, если массив содержит истинный бит.
bool BitArray::any() const
{
  int count = 0;
  for (int i = 0; i < this->_num_bits; i++)
  {
    if (bitarr[i] == 1)
    {
      count++;
    }
  }
  if (count == 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}
// true, если все биты массива ложны.
bool BitArray::none() const
{
  int count = 0;
  for (int i = 0; i < _num_bits; i++)
  {
    if (bitarr[i] == 1)
    {
      count++;
    }
  }
  if (count == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}
// Битовая инверсия

BitArray BitArray::operator~()
{
  char *temp = bitarr;
  for (int i = 0; i < _num_bits; i++)
  {
    temp[i] = bitarr[_num_bits - 1 - i];
  }
  for (int i = 0; i < _num_bits; i++)
  {
    bitarr[i] = temp[i];
  }
  return *this;
}

// Подсчитывает количество единичных бит.
int BitArray::count() const
{
  int count = 0;
  for (int i = 0; i < this->_num_bits; i++)
  {
    if (bitarr[i] == 1)
    {
      count++;
    }
  }
  return count;
}

// //Возвращает значение бита по индексу i.
bool BitArray::operator[](int i)
{
  return bitarr[i];
}

int BitArray::size() const
{
  return _num_bits;
}

bool BitArray::empty() const
{
  if (_num_bits == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Возвращает строковое представление массива.
std::string BitArray::to_string()
{
  std::string result = "";
    for (int i = _num_bits - 1; i >= 0; --i) {
        result += bitarr[i];
    }
  return result;
}

bool BitArray::operator==(const BitArray &b) const
{
  if (bitarr == b.bitarr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool BitArray::operator!=(const BitArray &b) const
{
  if (bitarr == b.bitarr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

BitArray BitArray::operator&(const BitArray &b) const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < b.size(); i++)
  {
    if (bitarr[i] == 1 && b.bitarr[i] == 1)
    {
      temp.bitarr[i] = 1;
    }
    else
    {
      temp.bitarr[i] = 0;
    }
  }
  return temp;
}
BitArray BitArray::operator|(const BitArray &b) const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < b.size(); i++)
  {
    if (bitarr[i] == 1 || b.bitarr[i] == 1)
    {
      temp.bitarr[i] = 1;
    }
    else
    {
      temp.bitarr[i] = 0;
    }
  }
  return temp;
}
BitArray BitArray::operator^(const BitArray &b) const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < b.size(); i++)
  {
    if (bitarr[i] == b.bitarr[i])
    {
      temp.bitarr[i] = 0;
    }
    else
    {
      temp.bitarr[i] = 1;
    }
  }
  return temp;
}