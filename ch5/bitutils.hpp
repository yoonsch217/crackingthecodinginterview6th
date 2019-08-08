#include <ostream>
#include <bitset>
#include <limits>

template <typename T, int N = std::numeric_limits<T>::digits>
std::bitset<N> bits(const T& value){
	return std::bitset<N>(value);
}

template <typename T>
size_t countBits(T v){
	static_assert(std::is_unsigned<T>::value, "T must be unsigned integer type");
	static_assert(std::numeric_limits<T>::digits <= 64, "Max 64 bits of T supported");

	constexpr const T m5 = static_cast<T>(0x5555555555555555U);
    constexpr const T m3 = static_cast<T>(0x3333333333333333U);
    constexpr const T m0F = static_cast<T>(0x0F0F0F0F0F0F0F0FU);

	v = v - ((v>>1) &  m5);
	v = (v & m3) + ((v >> 2) & m3);
	v = (v + (v >> 4)) & m0F;

# if 0
	constexpr const T m01 = static_cast<T>(0x0101010101010101U);
	v = v*m01 ;
	return v >> (std::numeric_limits<T>::digits -8);

# else
	if(std::numeric_limits<T>::digits > 8)
		v = (v+(v >> 8));
	if(std::numeric_limits<T>::digits > 16)
		v = (v + (v >> 16));;

	if(std::numeric_limits<T>::digits > 32)
		v = (v+(v>>32));

	return v& 0xFF;

#endif
}


