remove :: Eq a => [[a]] -> [a]
remove [] = []
remove xs = resultlist (flatList xs)


resultlist:: Eq a => [a] -> [a]
resultlist [] = []
resultlist (x:xs) | myElem x xs = resultlist xs
                  | otherwise = x : resultlist xs


flatList :: [[a]] -> [a]
flatList [] = []
flatList (x:xs) =  x ++ flatList xs


myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n (x:xs) | n == x = True
                | otherwise = myElem n xs

