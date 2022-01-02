## Big O

### 읽는 법

O(n): O of n
3^2: three squared
4^3: four cubed
2^5: two to the power of five, two to the fifth
1/3: one third
2/3: two thirds
1/n: one over n
quadratic time complexity => O(n^2)

### Big O / Big Omega / Big Theta
- Big O
Upper bound를 의미한다.
array 값을 출력하는 건 O(n)으로도 표현할 수 있지만 O(n^2)으로도 표현할 수 있다.
즉, 알고리즘이 이 시간보다 빠르지 않다는 것을 의미한다.
- Big Omega
Lower bound를 의미한다.
array 값 출력하는 건 Omega(n)으로도 표현할 수 있지만 Omega(1)로도 표현이 가능하다.
알고리즘이 이 시간보다 느리지 않다는 것을 의미한다.
- Big Theta
Tight bound를 의미한다.
Theta(n)인 알고리즘은 O(n) 이면서 Omega(n)이기도 하다.

일반적으로는 Big O와 Big Theta를 혼용해서 사용하고 있고 Big Theta의 의미로 사용된다.


### Best / Worst / Expected Case

일반적으로 best case는 고려하지 않는다.
worst case와 expected case가 동일한 경우가 많은데 그런 경우는 time complexity를 하나로 표현할 수 있다.
두 개가 다르다면 각각에 대해 time complexity를 나타내주는 것이 좋다.

### Drop constant / Drop non-dominant term

rate of increase를 계산하는 것이기 때문에 상수는 무시한다.
non-dominant term도 무시해야한다. 예를 들어 O(n^2 + n) 의 경우는 O(n^2)로 나타낸다. O(A^2 + B) 같은 경우에는 A와 B의 관계를 알기 전 까지는 둘 다 유지해야한다.

### Amortized Time

사이즈가 다 차면 두 배로 늘어나는 ArrayList에 대해 생각을 해보자.
사이즈를 늘릴 때 두 배 사이즈의 빈 Array를 만든 후 기존의 값들을 복사하는 것이기 때문에 사이즈가 꽉 찬 ArrayList에 insert하는 건 O(n)의 시간이 필요하다.
하지만 이런 특이 상황은 한번 일어나면 한동안 일어나지 않기 때문에 그 비용은 다음에 일어나기 전까지 amortized 된다.(분할상환)
정확히 계산을 하자면, n만큼의 insert를 하기 위해서 처음에 사이즈 1의 ArrayList를 사용했다고 하자. 
기본적으로 insert의 time complexity는 O(1) 인데 이제 여기에 resizing cost를 따져야한다.
resizing cost는 최대 n + n/2 + n/4 + ... + 1 = 2n일텐데 n번의 작업에 대한 cost이므로 평균 2n/n = 2 = O(1)이다.
따라서 결국 O(1)이라고 볼 수 있다.


## Technical Questions

알아야 할 내용
- Data Structures
Linked Lists, Trees, Tries, Graphs, Stacks, Queues, Heaps, Vectors, ArrayLists, HashTables
- Algorithms
Breadth-First Search, Depth-First Search, Binary Search, Merge Sort, Quick Sort
- Concepts
Bit Manipulation, Memory(Stack vs Heap), Recursion, Dynamic Programming, Big O Time & Space


### A problem-solving flow

1. Listen
1. Example
예시를 생각한다.
1. Brute Force
최대한 빨리 brute-force 방법을 생각한다. 아직 코드를 쓰지는 않는다.
1. Optimize
BUD Optimization: Bottleneck, Unnecessary work, Duplicated work
1. Walk Through
최적화된 답을 찾았다면 자세한 접근 과정을 설명한다.
1. Implement
좋은 코드를 작성한다.
1. Test
먼저 개념적으로 테스트를 한다.
그러고는 특별한 케이스들에 대한 테스트를 한다. 

예시를 생각하면 문제 해결에 큰 도움이 될 수 있다.
문제를 들으면 바로 예시를 그려보면서 문제를 이해한다.
예시를 들 때는 
- 실제 값들을 갖는 구체적인 예시
- 충분히 큰 규모의 예시
- 특별하지 않고 일반적인 예시(tree를 그릴 때 balanced tree를 그리지 않도록 하는 등)
를 생각하는 것이 좋다.

최적화를 할 때는
- 제시된 조건 중 사용되지 않은 조건이 있는지 확인한다.
- 새로운 에시를 생각해본다.
- space를 더 써서 time을 줄일 수 없을지 고려해본다.
- 데이터를 재구성하는 등 precompute 혹은 upfront work를 통해 전체의 time complexity를 줄인다.
- hash table을 사용한다.


BUD Optimization
- Bottleneck
O(n^2 + n)인 알고리즘이라면 O(n^2)인 부분을 최적화시켜야한다.
- Unnecessary Work
계산이 끝나면 break를 사용한다든가, 이전 절차를 통해 알 수 있는 값인데 한 번 더 계산하고 있지는 않은지 등을 확인해본다.
- Duplicated Work
이전에 계산한 값을 다시 사용하는 경우는 그 값을 저장해서 나중에 다시 계산하지 않도록 한다.


DIY
문제가 나오면 코드로 접근하지 말고 머리로 풀어본다.
그러고는 머리에서 일어난 과정들을 코드로 구현을 한다.
예를 들어, s = abbc, b = baasf..afe 가 있고 b 안에 있는 s의 permutation 수를 찾는다고 할 때 직접 찾아본다.
그러면 b의 캐릭터 하나 하나를 지나가면서 O(b)의 시간에 함을 알 수 있다.

Base Case and Build
복잡하다면 n=1과 같은 간단한 base case를 먼저 생각하고 어떻게 확장시킬지를 고민해본다.


Data Structure Brainstorm
어떤 자료구조를 사용해야할지 모르겠다면 알고 있는 자료구조들을 쫙 다 대입시켜보면서 되는지 확인해본다.

Best Conceivable Runtime(BCR)
(잘 이해 안 되면 73페이지 예시 확인)
예를 들어 array A, B를 출력한다고 하면 A와 B의 각 element를 한 번씩은 접근해야하므로 BCR은 O(A+B)가 된다.
최적화를 시킬 때 Brute force 시간과 BCR 시간 사이에서 최적화 작업을 하게 된다.
BCR 개념을 사용하게 되면 BCR보다 빠르거나 같은 어떤 작업도 time complexity에서 무시되기 때문에 upfront work로 활용해볼 수 있다.
또한 BCR에 다다랐다면 더 이상 최적화하지 않아도 된다. space comlexity가 O(1)이라면 더더욱



runtime을 생각할 때 이미 알고 있는 O(n), O(nlogn), ... 등만 생각하지 않는다.
O(kn^c)와 같은 runtime이 나올 수 있다.

좋은 코드란
- correct
- efficient: big O 뿐만 아니라 constant 부분이라 big O에 포함되지 않는 부분까지도 효율적이면 좋다.
- simple: 코드 줄이 적으면 좋다.
- readable: 필요하다면 주석을 달아서 가독성을 높인다.
- maintainable: 다른 개발자, 혹은 신입 개발자에 의해서도 유지보수가 될 수 있어야한다.

function을 만들 때 하나의 함수로 여러 함수를 구현할 수 있다면 좋다.

modular code를 사용하게 되면 긴 코드 일부분을 따로 떼어내는 것이다.
이렇게 하면 각각 테스트가 가능하기 때문에 효율적인 코드가 된다.

에러 체킹 코드도 넣으면 좋다.
입력값에 대한 조건을 다는 것 보다는 그 입력값이 들어왔을 때도 동작할 수 있도록 assert나 if-else로 처리해준다.
시간이 부족하다면 해당 부분을 공백으로 두고 나중에 구현하겠다고 말한다.
즉, 인지하고 있다는 것은 티를 내준다.



