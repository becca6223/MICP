from sets import Set
import numpy as np

#Create unit test cases for python 
array = None #test case 1  
array1 = [] #test case 2
array2 = [0,1] #test case 3
array3 = [0,1,-1] #test case 4
array4 = [0,1,1] #test case 5
array5 = [2,0,-1,-2,1] #test case 6 
array6 = [0,0,0,0,0] #test case 7
array7 = [3,-1,-1,-1,0,-3,2, -6,6,-3] #test case 8

Arrays =[array, array1, array2, array3, array4, array5, array6, array7]
Num_arrays_in_Arrays = len(Arrays) 

#Define Functions

#cehck input function
def Check_Input(current_array):
    if current_array is None or current_array == []:
  		return False 
    if not(all(isinstance(element, int) for element in current_array)):
    	return False
    return True 

#get length of current array
def Current_Array_Length(current_array):
	length = len(current_array)
	return length

#Find all the possibilities for 3 numbers sum it up to 0 in current_array
def Get_Unique_Triplets(ArrayLength, current_array):
    
	#Special case for only 3 elements in the array
    if(ArrayLength == 3): 
        SumArray = sum(current_array)
        if(SumArray == 0):
            sortArray = sorted(current_array)
            return(sortArray)
        else:
            return None
	
	#Special case for all the elements are the same in the array
    if(all(current_number == 0 for current_number in current_array)):
        return([0,0,0])
    
	#Special case if all numbers are positive or negative
    if(all(current_number <= 0 for current_number in current_array)):
	    return(None)
    if(all(current_number >= 0 for current_number in current_array)):
        return(None)

    #General Case
    ResultArray = General_Case_in_Get_Unique_Triplets(ArrayLength, current_array)
    return(ResultArray)

def General_Case_in_Get_Unique_Triplets(ArrayLength, current_array):
    ResultArray = []    
    current_array.sort()
    LeftPointer = 0 #beginning pointer in current_array
    StopPointer = 0 
    MaxPointer = ArrayLength
    for i in current_array: 
        if i >= 0:
            StopPointer = current_array.index(i)
            break
   
    temp = []
    while(LeftPointer < StopPointer):
        c = LeftPointer + 1
        setArray = set(current_array[c:MaxPointer])
        setSize = len(setArray)
        while(setSize > 0 and c < ArrayLength):
            temp.append(current_array[LeftPointer])
            searchValue = 0 - (current_array[LeftPointer] + current_array[c])
            setArray.discard(current_array[c])
            if(searchValue in setArray):
                temp.append(current_array[c])
                temp.append(searchValue)
                ResultArray.append(temp)
                #discard searchvalue				
                while searchValue in setArray:
                    setArray.remove(searchValue)
            temp = [] 
			
			#Skip the same value, otherwise will get same triplet
            ValueToBeDiscard = current_array[c]
            check = False
            while(c + 1 < ArrayLength and ValueToBeDiscard == current_array[c+1]):
                setArray.discard(ValueToBeDiscard)
                c = c + 1
                check = True
            if check == False:
                c = c + 1   
        
        for i in current_array[LeftPointer+1:ArrayLength]:
            if i != current_array[LeftPointer]:
                LeftPointer = current_array.index(i)
                break
    
    if(ResultArray == []):
	   return None
    else:
	    return ResultArray

#main function
for current_array in Arrays:
    InputValidation = Check_Input(current_array)
    #print InputValidation
    if InputValidation == True:
        ArrayLength = Current_Array_Length(current_array)
        if ArrayLength >= 3:
	        print Get_Unique_Triplets(ArrayLength, current_array)
        else:
            print None   
    else:
        print None
        
	

  
