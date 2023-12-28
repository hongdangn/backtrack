char nextGreatestLetter(char* letters, int lettersSize, char target){
    if(target >= letters[lettersSize - 1] || target < letters[0])
    {
        return letters[0];
    }
    else
    {
        if(lettersSize == 2){return letters[lettersSize - 1];}
        else
        {
            int left = 0, right = lettersSize - 1;
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                if(letters[mid] == target)
                {
                    int j = mid;
                    while(letters[j] == target)
                    {j++;}
                    return letters[j];
                }
                if(letters[mid] > target)
                {
                    if(letters[mid - 1] <= target)
                    {
                        return letters[mid];
                    }
                    else right = mid - 1;
                }
                if(letters[mid] < target)
                {
                    if(letters[mid + 1] > target)
                    {
                        return letters[mid + 1];
                    }
                    else left = mid + 1;
                }
            }
            return letters[right];
        }
    }
}
