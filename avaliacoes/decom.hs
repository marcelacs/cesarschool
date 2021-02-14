aplicador :: [(a -> b -> b)] -> a -> b -> [b]
aplicador [] _ _ = []
aplicador xs a b =  decom'(decom xs a) b

decom :: [(a -> b -> b)] -> a -> [(b -> b)]
decom [] _ = []
decom (x:xs) n  = x n : decom xs n

decom' :: [a -> b] -> a -> [b]
decom' [] _ = []
decom' (x:xs) n = x n : decom' xs n 