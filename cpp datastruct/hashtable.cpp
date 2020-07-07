#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <memory>

template <typename Key, typename T, typename Hash = std::hash<Key>>
class hash_map {
public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<const key_type, mapped_type>;
    using size_type = size_t;
    using hasher = std::hash<Key>;    

private:  // helper
    using wrapper = std::shared_ptr<value_type>;

public:  // constructor
    hash_map() {
        container_.resize(primes_[size_level_]);
    }



}