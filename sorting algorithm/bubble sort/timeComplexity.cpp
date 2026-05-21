// What happens in bubble sort?
// For array of size n:

// Pass 1 → n-1 comparisons
// Pass 2 → n-2 comparisons
// Pass 3 → n-3 comparisons
// ...
// Pass n-1 → 1 comparison


// Total comparisons:
// (n-1) + (n-2) + (n-3) + ... + 1
// This is sum of first n-1 natural numbers:
// = (n-1)(n-1+1) / 2
// = (n-1)(n) / 2
// = n²/2 - n/2

// Applying Big O:
// In Big O we:

// Drop constants → n²/2 becomes n²
// Drop lower order terms → -n/2 is dropped

// So:
// O(n²)

// Three cases:
// CaseConditionComplexityBestArray already sortedO(n) — flag breaks after 1st passAverageRandom orderO(n²)WorstArray reverse sortedO(n²)

// Best case explained:
// Pass 1 runs → no swap happens → flag stays true → breaks immediately after 1 pass of n-1 comparisons → O(n)
// That's why the flag optimization matters.