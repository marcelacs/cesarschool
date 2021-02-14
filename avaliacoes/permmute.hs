permute :: Ord a => [a] -> [[a]]
permute [] = [[]]
permute [a] = [[a]]
permute [a,b] | a == b = [[a,b]]
              | [a,b] > [b,a] =  [[b,a],[a,b]]
              | otherwise = [[a,b], [b,a]]
permute x = sortList (removeEqual (rotateList x)) 

rotateList :: [a] -> [[a]]
rotateList  [] = [[]] 
rotateList  (x:xs) = myFoldr (++) [] (myMap (myInterleave [] x) (rotateList xs))

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (a:as) = (f a) : myMap f as


myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ y [] = y
myFoldr f y (x:xs) = f x (myFoldr f y xs)


myInterleave :: [a] -> a -> [a] -> [[a]]
myInterleave xs x [] =  [xs ++ [x]]
myInterleave xs x (y:ys) = (xs ++ (x:y:ys)) : (myInterleave (xs ++ [y]) x ys)


removeEqual :: Eq a => [[a]] -> [[a]]
removeEqual [] = []
removeEqual (x:xs) | myElem  x xs = removeEqual xs
                   | otherwise = x : removeEqual xs
 

sortList :: Ord a => [a] -> [a]
sortList [] = [] 
sortList (x:xs) = (sortList (filter (<x) xs)) ++ [x] ++ (sortList(filter (>x) xs)) 


myElem :: Eq a => [a] -> [[a]] -> Bool
myElem n [] = False
myElem n (x:xs) | n == x = True
                | otherwise = myElem n xs
