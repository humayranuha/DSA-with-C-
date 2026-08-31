// Implementing hash table in C++

#include <iostream>
#include <list>
#include <utility>
using namespace std;

class HashTable
{
    int capacity;
    list<pair<int, int>> *table;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);
    int hashFunction(int key);
    void displayHash();

private:
    int checkPrime(int n);
    int getPrime(int n);
};

int HashTable::checkPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int HashTable::getPrime(int n)
{
    if (n <= 1)
        return 2;
    if (n % 2 == 0)
        n++;

    while (!checkPrime(n))
    {
        n += 2;
    }
    return n;
}

HashTable::HashTable(int c)
{
    int size = getPrime(c);
    this->capacity = size;
    table = new list<pair<int, int>>[capacity];
}

int HashTable::hashFunction(int key)
{
    return (key % capacity);
}

void HashTable::insertItem(int key, int data)
{
    int index = hashFunction(key);
    table[index].push_back({key, data});
    cout << "Inserted: key=" << key << ", data=" << data << " at index " << index << endl;
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    int count = 0;

    // Use a while loop to safely delete multiple items
    for (auto it = table[index].begin(); it != table[index].end();)
    {
        if (it->first == key)
        {
            cout << "Deleting: key=" << it->first << ", data=" << it->second << endl;
            it = table[index].erase(it);
            count++;
        }
        else
        {
            ++it;
        }
    }

    if (count > 0)
        cout << "Key " << key << " deleted " << count << " time(s)!" << endl;
    else
        cout << "Key " << key << " not found!" << endl;
}

void HashTable::displayHash()
{
    cout << "\n--- Hash Table ---" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << "table[" << i << "]";
        if (table[i].empty())
        {
            cout << " --> empty" << endl;
        }
        else
        {
            for (auto x : table[i])
                cout << " --> (" << x.first << ", " << x.second << ")";
            cout << endl;
        }
    }
}

int main()
{
    int key[] = {231, 321, 212, 321, 433, 262};
    int data[] = {123, 432, 523, 43, 423, 111};
    int size = sizeof(key) / sizeof(key[0]);

    cout << "Creating hash table with capacity: " << size << endl;
    cout << "Prime capacity used: " << size << " (7 is prime)" << endl
        << endl;

    HashTable h(size);

    // Insert all items
    for (int i = 0; i < size; i++)
    {
        h.insertItem(key[i], data[i]);
    }

    h.displayHash();

    cout << "\n--- Deleting key 321 (both occurrences) ---" << endl;
    h.deleteItem(321);

    h.displayHash();

    cout << "\n--- Deleting key 999 (doesn't exist) ---" << endl;
    h.deleteItem(999);

    h.displayHash();

    return 0;
}