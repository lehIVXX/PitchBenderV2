int clipValue(int in, int minVal, int maxVal){ 
int out; 
minVal++; 
if (in > maxVal) { 
 out = maxVal; 
} 
else if (in < minVal) { 
out = minVal -1; 
} else { 
out = in; 
} 
return out;
};
