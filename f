********************************************************************************************
*                                                                                          *
*                       FT_CONTAINERS TEST by @elaronda and @cshells                       *
*                                                                                          *
********************************************************************************************
--------------------------------------------------------------------------------------------
|                                          VECTOR                                          |
--------------------------------------------------------------------------------------------
FUNCTION                      [1;39mRESULT[0m             [1;39mFT TIME[0m            [1;39mSTD TIME[0m           [1;39mLEAKS[0m              
constructor                   [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;31mLEAKS[0m              
constructor(std iterators)    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;31mLEAKS[0m              
iterators                     [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;31mLEAKS[0m              
begin()                       [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
end()                         [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
rbegin()                      [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
rend()                        [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
size()                        [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
max_size()                    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
resize()                      [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
capacity()                    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
empty()                       [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
reserve()                     [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
operator[]                    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
at()                          [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
front()                       [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
back()                        [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
assign()                      [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
assign(std iterators)         [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
push_back()                   [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
pop_back()                    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
insert(value)                 [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
insert(fill)                  [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
insert(range)                 [1;31mFAILED[0m             [1;32m0ms[0m                [1;32m0ms[0m                [1;31mLEAKS[0m              
insert(std iterators)         [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
erase(value)                  [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
erase(range)                  [1;32mOK[0m                 [1;31m1ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
swap()                        [1;32mOK[0m                 [1;31m1ms[0m                [1;32m0ms[0m                [1;31mLEAKS[0m              
clear()                       [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                [1;32mCLEAR[0m              
using allocator               [1;32mOK[0m                 
operator ==                   [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                
operator !=                   [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                
operator <                    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                
operator >                    [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                
operator <=                   [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                
operator >=                   [1;32mOK[0m                 [1;32m0ms[0m                [1;32m0ms[0m                

[1;33mVECTOR RESULT: 31/36[0m

See 📄 [1mlogs.txt[0m for more information. 
[1mWARNING:[0m it will be rewrite next execution
