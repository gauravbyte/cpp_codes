/* 
1. There are two signal filters A and B in a signal transmitter, and each receives a sequence of signal values
 with some distortion in the signal values. Each filter works iteratively, correcting the distortion values in 
 the signal and then adds the distortion value to its score and then repeats the process, and then it is the turn 
 of the next filter and so on. Each time, the filter can only pick the value from the first or last of the sequence. 
 The filter A tries to maximise the number of distortions it corrects, while the filter B tries to minimise the number of distortions the first filter corrects. What is the maximum number of distortions the filter A can correct, given both filters work optimally. The filter A has the first turn. After a signal is corrected, that value is removed from the sequence.

	Example - 
	Input:
	7
	5 10 8 11 6 2 3

	Solution:
	A = 5 + 8 + 6 + 2 = 21
	B = 10 + 11 + 3 = 24
	
	So the answer is 21
	
	The constraints were both 106 that is the size of the a
    rray and also the values in the array.
	The output format was like - “print an integer 
    denoting the maximum number of distortions A can correct
    , and if the output is not possible, then do not print anything”.
	There were around 14 test cases, and two were visible.
 */
