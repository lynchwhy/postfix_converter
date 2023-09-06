template <typename T>
LQueue<T>::LQueue()
{
  list = new std::list<T>();
  count = 0;
}

template <typename T>
LQueue<T>::~LQueue()
{
  delete list;
  count = 0;
}

template <typename T>
void LQueue<T>::enqueue(const T& data)
{
  list->push_back(data);
  count++;
}

template <typename T>
T LQueue<T>::dequeue()
{
  if (list->empty()) throw empty_collection_exception();
  T value = list->front();
  list->pop_front();
  count--;
  return value;
}

template <typename T>
T& LQueue<T>::front()
{
  return list->front();
}

template <typename T>
int LQueue<T>::size() const
{
  return list->size();
}

template <typename T>
bool LQueue<T>::empty() const
{
  return list->empty();
}

