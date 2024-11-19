// 1 is easy (EV is always 1)
//
// 2...
// The answer is simply the lengths of all paths that are possible on the tree, divided by the number of paths possible on the tree.
//
// 3..
// Actually, for odd numbers, the answer might possibly be 1 and 1 only
// By moving from a good island, the next island is never good, because you are moving away from k islands and moving towards k-1 islands (or the other way around) so the net difference is never 0. From this we can at least prove for odd numbers there are no good islands that is an odd distance from another good island.
//
// Obviously, if you start from the good island, other good islands must be a simple path away. If so, and you move along the simple path, then you are moving away from the same k or k-1 islands no matter how you travel, so you will always have a positive or negative net differnce. Thus we have proved, for odd numbers, the answer is always 1. Then the answer is trivial for the easy portion of the problem. Now, the real challenge is to solve even numbers that are greater than 2. 
//
//
// 4 and other even numbers:
// We know that for some arrangement of friends, region that is considered good is enclosd in a simple path. For each of these paths, there are multiple ways to scatter the friends around them such that each side of the path contains half of the friends. 
