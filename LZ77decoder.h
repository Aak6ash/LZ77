#ifndef LZ77DECODER_H_INCLUDED
#define LZ77DECODER_H_INCLUDED

/*Generate the original string from the output tuples
*
*Parameter
*test_Len	length of the original string
*offset		the offset of the match found
*length	    length of the match found
*ch	        the character to be added in the decoded sequence
*test		the original string
*output_len	length of the output string
*No Return value
*Output is the original string
*/

void decoder();

#endif
