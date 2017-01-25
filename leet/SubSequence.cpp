/* Go through all the characters IN ORDER in the smaller string
** and check if they occur IN ORDER in the larger string.
** If we have reached the end of the smaller string, then
** it is a subsequence */


#include <iostream>
#include <vector>

bool IsSubsequence(std::string big, std::string sml)
{
	int bigLen = big.size();
	int smlLen = sml.size();
	if(bigLen == 0 || smlLen == 0)
		return false;
	int i=0,j = 0;
	while ( i < bigLen)
	{
		if(j >= smlLen )
			break;
		if(sml[j] == big[i])
			++j;
		++i;
	}
	return (j == smlLen); 
}
		

int main(int argc, char const *argv[])
{
	std::cout<<"answer is "<< IsSubsequence("thisisthebiggerstring","") <<std::endl;
}
