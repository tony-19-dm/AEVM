#include <mySimpleComputer.h>

void
sc_updateCacheAfterSave (int memaddress, int cacheLine, int *value)
{
  static int currentIndex = 0;
  static int countIt = 0;
  if (updateStatic == 1)
    {
      currentIndex = 0;
      countIt = 0;
      updateStatic = 0;
    }

  // initStatics(&currentIndex, &countIt);
  *value = RAM[memaddress];

  int address = (cacheLine / 10) * 10;
  int cacheHit = 0; // Флаг для проверки попадания в кеш

  // Проверяем, есть ли уже запись в кеше для данного адреса
  for (int i = 0; i < CACHE_SIZE; ++i)
    {
      if (cache[i].address == address)
        {

          cacheHit = 1;
          currentIndex = i; // Запоминаем индекс строки кеша, в которую попали
          break;
        }
    }

  if (!cacheHit)
    {
      // Если не было попадания в кеш, добавляем новую запись
      if (countIt < CACHE_SIZE)
        {

          currentIndex = countIt; // Используем индекс, равный текущему числу
                                  // записей в кеше
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              cache[currentIndex].data[j] = RAM[address + j];
            }
          cache[currentIndex].address = address;
          cache[currentIndex].lastAccessTime
              = time (NULL); // Обновляем время последнего доступа
          countIt++;
        }
      else
        {
          // Если кеш полон, заменяем наименее используемую запись
          currentIndex = sc_findLeastRecentlyUsedCacheEntry ();
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              RAM[cache[currentIndex].address + j]
                  = cache[currentIndex].data[j];
            }
          for (int j = 0; j < CACHE_LINE_SIZE; ++j)
            {
              cache[currentIndex].data[j] = RAM[address + j];
            }
          cache[currentIndex].address = address;
          cache[currentIndex].lastAccessTime = time (NULL);
        }
    }
  else
    {
      // Если было попадание в кеш, обновляем существующую запись
      for (int j = 0; j < CACHE_LINE_SIZE; ++j)
        {
          cache[currentIndex].data[j] = RAM[address + j];
        }
      cache[currentIndex].lastAccessTime = time (NULL);
    }
}

int
initStatics (int flag)
{
  if (flag == 0)
    {
      return 0;
    }
  return flag;
}