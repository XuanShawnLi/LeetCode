#include<iostream>
#include<tr1/functional>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;

struct Key
{
  std::string first;
  std::string second;
  int         third;

  bool operator==(const Key &other) const
  { return (first == other.first
            && second == other.second
            && third == other.third);
  }
};

struct KeyHasher
{
  std::size_t operator()(const Key& k) const
  {
    using std::size_t;
    using std::tr1::hash;
    using std::string;

    return ((hash<string>()(k.first)
             ^ (hash<string>()(k.second) << 1)) >> 1)
             ^ (hash<int>()(k.third) << 1);
  }
};

int main()
{
  unordered_map<Key,string, KeyHasher> m6;// = { { {"John", "Doe", 12}, "example"}, { {"Mary", "Sue", 21}, "another"}  };
}
