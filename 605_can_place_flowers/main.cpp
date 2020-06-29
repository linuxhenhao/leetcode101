#include <vector>
#include <iostream>


class Solution {
    public:
        bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
      if (n == 0) {
        return true;
      }
	    std::vector<int>::iterator it;	            
	    it = flowerbed.begin();
	    flowerbed.insert(it, 0);
	    it = flowerbed.end();
	    flowerbed.insert(it, 0);
	    int size = flowerbed.size();
	    for (int i=1; i < size - 1; ) {
        if (flowerbed[i] != 0) {
          i+=2;
          continue;
        }
	    	if (flowerbed[i-1] == 0) {
		       if (flowerbed[i+1] == 0) {
		 	        --n;
		          if(n==0) {return true;}
			        i += 2;	
		       } else {
		     	    i += 3;
		       }
		    } else {
		       ++i;
		    }
	    }
	    return false;
	}
};


int main() {
    auto bed = std::vector<int>({1, 0});
    auto s = Solution();
    std::cout<<s.canPlaceFlowers(bed, 1)<<std::endl;
    return 0;
}
