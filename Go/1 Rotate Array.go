/*
Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4]
*/

package main

import (
	"encoding/json"
	"fmt"
)

func rotateArray(n int, k int, arr []int) []int {
	startSlice := arr[n-k:]
	endSlice := arr[:n-k]
	return append(startSlice, endSlice...)
}

func rotateArray2ndMethod(n int, k int, arr []int) []int {
	newArray := make([]int, n)

	for i := 0; i < n; i++ {
		newArray[(k+i)%n] = arr[i]
	}

	return newArray
}

func main() {
	nosElement := 7
	steps := 3
	array := []int{1, 2, 3, 4, 5, 6, 7}
	solution := []int{5, 6, 7, 1, 2, 3, 4}

	result := rotateArray(nosElement, steps, array)
	fmt.Println(result)

	if equalArrays(result, solution) {
		fmt.Println("Matched")
	} else {
		fmt.Println("Error in the Code")
	}
}

func equalArrays(arr1 []int, arr2 []int) bool {
	arr1JSON, _ := json.Marshal(arr1)
	arr2JSON, _ := json.Marshal(arr2)
	return string(arr1JSON) == string(arr2JSON)
}
