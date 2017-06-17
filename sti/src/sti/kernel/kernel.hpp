#pragma once

#include <array>

namespace sti
{
namespace kernel
{

/*!
 * convolution story.
 */
template <typename T, int Size>
class kernel
{
    using value_type = std::array<T, Size * Size>;
    using iterator = typename value_type::iterator;
    using const_iterator = typename value_type::const_iterator;

public:
    inline const int size() const
    {
        return Size;
    }

    inline iterator begin()
    {
        return data_.begin();
    }

    inline iterator end()
    {
        return data_.end();
    }

    inline const_iterator begin() const
    {
        return data_.begin();
    }

    inline const_iterator end() const
    {
        return data_.end();
    }

    /*!
     * \todo improve safety by solving the initial problem of accessing the
     * kernel differently.
     */
    inline const T *operator[](const int y) const
    {
        return &data_[y * Size];
    }

    inline T *operator[](const int y)
    {
        return &data_[y * Size];
    }

    T factor = static_cast<T>(1.0);
    T offset = static_cast<T>(0.0);

    void dump(FILE *fp)
    {
        if (!fp)
            // \todo report error
            return;

        for (int y = 0; y < Size; ++y)
        {
            for (int x = 0; x < Size; ++x)
            {
                fprintf(fp, "%f ", this->operator[](y)[x]);
            }
            fprintf(fp, "\n");
        }
    }

private:
    value_type data_;
};

} // namespace kernel
} // namespace sti
