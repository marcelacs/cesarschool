
removeLargeN :: Ord a => Int -> [a] -> [a]
removeLargeN _ [] = []
removeLargeN 0 xs = xs
removeLargeN n xs | n > length xs = xs
                  | otherwise = rmOrd (rmvNLarge n (orderList 1 xs))

findN :: (Eq a, Num a) => a -> [b] -> b
findN 1 (x:xs) = x 
findN n (x:xs) = findN (n-1) xs

sortList :: Ord a => [a] -> [a]
sortList [] = []
sortList (x:xs) = (sortList (filter (>=x) xs)) ++ [x] ++ (sortList (filter (<x) xs))


findSort :: (Num a, Ord b, Eq a) => a -> [b] -> b
findSort _ [a] = a
findSort n xs = findN n (sortList (xs))

rmvNLarge :: (Num a, Ord b, Eq a) => a -> [b] -> [b] 
rmvNLarge n xs  = removeN (findSort n xs) xs

removeN :: Eq a => a -> [a] -> [a]
removeN n (x:xs) | x == n = xs
                 | otherwise = x : removeN n xs


count :: (Num b, Eq a) => a -> [a] -> b
count _ [] = 0
count n (x:xs) | (n == x) = 1 + count n xs
               | otherwise = count n xs

orderList :: Num b => b -> [a] -> [(a, b)]
orderList _ [] = []
orderList n (x:xs) = (x,n) : orderList (n+1) xs


rmOrd :: [(a, b)] -> [a]
rmOrd [] = []
rmOrd ((x,n):xs) = x: rmOrd xs
