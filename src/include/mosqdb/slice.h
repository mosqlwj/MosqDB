//
// Created by lwj on 22-8-30.
//

#ifndef MOSQDB_SLICE_H
#define MOSQDB_SLICE_H
#include <cassert>
#include <cstddef>
#include <string.h>
#include <string>

namespace mosqdb {

  class Slice {
  public:
    Slice() : data_(""), size_(0) {}

    Slice(const char* d, size_t n) : data_(d), size_(n) {}

    Slice(const std::string& s) : data_(s.data()), size_(s.size()) {}

    Slice(const char* s) : data_(s), size_(strlen(s)) {}

    Slice(const Slice&) = default;
    Slice& operator=(const Slice&) = default;

    const char* Data() const { return data_; }

    size_t Size() const { return size_; }

    bool Empty() const { return size_ == 0; }

    char operator[](size_t n) const {
        assert(n < size_);
        return data_[n];
    }

    void Clear() {
        data_ = "";
        size_ = 0;
    }

    void RemovePrefix(size_t n) {
        assert(n <= size_);
        data_ += n;
        size_ -= n;
    }

    std::string ToString() const {
        return std::string(data_, size_);
    }

    int Compare(const Slice& b) const;

    bool StartWith(const Slice& x) const {
        return ((size_ >= x.size_)) && (memcmp(data_, x.data_, x.size_) == 0);
    }
  private:
    const char* data_;
    size_t size_;
  };

    inline bool operator==(const Slice& x, const Slice& y) {
        return ((x.Size() == y.Size())) &&
                (memcmp(x.Data(), y.Data(), x.Size()) == 0);
    }

    inline bool operator!=(const Slice& x, const Slice& y) {
        return !(x == y);
    }

    inline int Slice::Compare(const mosqdb::Slice &b) const {
        const size_t min_len = (size_ < b.size_) ? size_ : b.size_;
        int r = memcmp(data_, b.data_, min_len);
        if (r == 0) {
            if (size_ < b.size_) {
                r = -1;
            } else if (size_ > b.size_) {
                r = +1;
            }
        }
        return r;
    }
}


#endif //MOSQDB_SLICE_H
