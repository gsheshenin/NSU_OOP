#include ".//bitarr.hpp"
#include <iostream>
#include <cstring>


// Обменивает значения двух битовых массивов. 
void BitArray::swap(BitArray &b)
{
  std::swap(_num_bits, b._num_bits);
  std::swap(bitarr, b.bitarr);
}

BitArray &BitArray::operator=(const BitArray &b)
{
  if (b == *this){
    std::cout << "the massives are already equal"
              << "\n";
    return *this;
  }
  _num_bits = b._num_bits; // проверка на b != this
  for (int i = 0; i < _num_bits; i++)
  {
    bitarr[i] = b.bitarr[i];
  }
  return *this;
}

// Изменяет размер массива. В случае расширения, новые элементы
// инициализируются значением value.
void BitArray::resize(int num_bits, bool value /*= false*/)
{
  if (_num_bits == num_bits)
  {
    return;
  }
  BitArray temp2(num_bits, 0);
  if (_num_bits > num_bits)
  {
    for (int i = 0; i < _num_bits; i++)
    {
      temp2.bitarr[i] = bitarr[i];
    }
    delete[] bitarr;
    _num_bits = num_bits;
    bitarr = temp2.bitarr;
    temp2.clear();
  }
  else
  {
    for (int i = 0; i < _num_bits; i++)
    {
      temp2.bitarr[i] = bitarr[i];
    }
    for (int j = _num_bits; j < _num_bits; j++)
    {
      temp2.set(j, value);
    }
    delete[] bitarr;
    _num_bits = _num_bits;
    bitarr = temp2.bitarr;
    temp2.clear();
  }
}
// Очищает массив.
void BitArray::clear()
{
  _num_bits = 0;
  delete[] bitarr;
}

// Добавляет новый бит в конец массива. В случае необходимости
// происходит перераспределение памяти.

void BitArray::push_back(bool bit)
{
  int count;
  BitArray temp2;
  temp2._num_bits = _num_bits;
  temp2.bitarr = bitarr;
  if (temp2[_num_bits * 8 - 1] == 1){
    temp2.resize(1, 0);
    temp2.set(8 * _num_bits, 1);
    _num_bits = temp2._num_bits;
    bitarr = temp2.bitarr;
    temp2.clear();
    return;
  }
  else{
    for (int i = 0; i < 8 * _num_bits; i++){
      if(temp2[i] == 1){
        count = i;
      }
    }
    temp2.set(count + 1, 1);
    bitarr = temp2.bitarr;
    temp2.clear();
    return;
  }
}

// //Битовые операции над массивами.
// //Работают только на массивах одинакового размера.
// //Обоснование реакции на параметр неверного размера входит в задачу.

BitArray &BitArray::operator&=(const BitArray &b)
{
  BitArray temp2 = b;
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  temp = temp & temp2;
  _num_bits = temp._num_bits;
  bitarr = temp.bitarr;
  return *this;
}

BitArray &BitArray::operator|=(const BitArray &b)
{
  BitArray temp2 = b;
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  temp = temp | temp2;
  _num_bits = temp._num_bits;
  bitarr = temp.bitarr;
  return *this;
}
BitArray &BitArray::operator^=(const BitArray &b)
{
  BitArray temp2 = b;
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  temp = temp ^ temp2;
  _num_bits = temp._num_bits;
  bitarr = temp.bitarr;
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
 void BitArray::set(int n, bool val /*= true*/) /*BitArray&*/
{
  if (n >= _num_bits * 8 || n < 0)
  {
    std::cout << "index out of range"
              << "\n";
  }
  else
  {
    int byteindex = n / 8;
    int bitindex = n % 8;
    if (val){
      bitarr[byteindex] |= (1 << bitindex);
    }
    else{
      bitarr[byteindex] &= ~(1 << bitindex);
    }
  }
}
// Заполняет массив истиной.
BitArray &BitArray::set()
{
  for (int i = 0; i < 8 * _num_bits; i++)
  {
    set(i, true);
  }
  return *this;
}

// Устанавливает бит с индексом n в значение false.
BitArray &BitArray::reset(int n)
{
  if (n > _num_bits * 8 || n < 0)
  {
    std::cout << "index out of range"
              << "\n";
  }
  else
  {
    set(n, false);
  }
  return *this;
}

// Заполняет массив ложью.
BitArray &BitArray::reset()
{
  for (int i = 0; i < 8 * _num_bits; i++)
  {
    set(i, false);
  }
  return *this;
}

// true, если массив содержит истинный бит.
bool BitArray::any() const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  int count = 0;
  for (int i = 0; i < _num_bits * 8; i++)
  {
    if (temp[i] == 1)
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
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  int count = 0;
  for (int i = 0; i < _num_bits * 8; i++)
  {
    if (temp[i] == 1)
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

BitArray BitArray::operator~() const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for(int i = 0; i < _num_bits * 8; i++){
      if (temp[i] == 1){
        temp.set(i, false);
      }
      else{
        temp.set(i, true);
      }
  }
  return temp;
}

// Подсчитывает количество единичных бит.
int BitArray::count() const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  int count = 0;
  for (int i = 0; i < 8 * _num_bits; i++)
  {
    if (temp[i] == 1)
    {
      count++;
    }
  }
  return count;
}

// //Возвращает значение бита по индексу i.
bool BitArray::operator[](int i)
{
  int temp = i / 8;
  int temp2 = i % 8;
  char mask = 1 << temp2;
  return bitarr[temp] & mask;
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
std::string BitArray::to_string() const
{
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  std::string result = "";
  for (int i = _num_bits * 8 - 1; i >= 0; --i) {
    if (temp[i] == 1){
      result += "1";
    }
    else{
      result += "0";
    }
  }
  return result;
}

bool BitArray::operator==(const BitArray &b) const
{
  return bitarr == b.bitarr;
}

bool BitArray::operator!=(const BitArray &b) const
{
  return bitarr != b.bitarr;
}

BitArray BitArray::operator&(const BitArray &b) const
{
  BitArray temp2 = b;
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < b.size() * 8; i++)
  {
    if (temp[i] == 1 && temp2[i] == 1)
    {
      temp.set(i, true);
    }
    else
    {
      temp.set(i, false);
    }
  }
  return temp;
}
BitArray BitArray::operator|(const BitArray &b) const
{
  BitArray temp2 = b;
  BitArray temp;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < b.size() * 8; i++)
  {
    if (temp[i] == 1 || temp2[i] == 1)
    {
      temp.set(i, true);
    }
    else
    {
      temp.set(i, false);
    }
  }
  return temp;
}
BitArray BitArray::operator^(const BitArray &b) const
{
  BitArray temp;
  BitArray temp2 = b;
  temp._num_bits = _num_bits;
  temp.bitarr = bitarr;
  for (int i = 0; i < b.size(); i++)
  {
    if (temp[i] == temp2[i])
    {
      temp.set(i, false);
    }
    else
    {
      temp.set(i, true);
    }
  }
  return temp;
}