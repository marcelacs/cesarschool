oddTimes :: Ord a => [a] -> [a]
oddTimes [] = [] 
oddTimes xs = sortList (removeEven xs)

count :: Eq a => a -> [a] -> Int
count _ [] = 0
count n (x:xs) | (n == x) = 1 + count n xs
               | otherwise = count n xs

removeEven :: Eq a => [a] -> [a] 
removeEven [] = []
removeEven (x:xs) | mod  (count x xs) 2 == 0 =  x:removeEven xs
                 | otherwise = removeEven (removeEqual x (x:xs))

removeEqual :: Eq a => a -> [a] -> [a]
removeEqual _ [] = []
removeEqual n (x:xs) | n == x = removeEqual n xs
                     | otherwise = x : removeEqual n xs

sortList :: Ord a => [a] -> [a]
sortList [] = []
sortList (x:xs) = (sortList (filter (>=x) xs)) ++ [x] ++ (sortList (filter (<x) xs))