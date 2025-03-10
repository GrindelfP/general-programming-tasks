template<typename T, typename I>
I dremove(I start, I fin, T value);


template<typename P, typename I>
I dremove(I start, I fin, P pred);

template<typename I, typename F>
I dremove(I start, I fin, F fucnt);

