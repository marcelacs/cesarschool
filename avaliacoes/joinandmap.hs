joinAndMap :: (t1 -> t2 -> t3) -> (t3 -> a) -> [t1] -> [t2] -> [a]
joinAndMap f n _ [] = []
joinAndMap f n [] _ = [] 
joinAndMap f n (x:xs) (y:ys) = n (f x y) : joinAndMap f n xs ys