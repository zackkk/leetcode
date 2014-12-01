Lowest Common Ancestor

1. Binary Search Tree
	if(root == p || root == q) return root;
	if(max(p, q) < root) search left;
	if(min(p, q) > root) search right;
	return root;

2. Binary Tree

	> Top-Bottom

		count the number of nodes in the left subtree
		if(count == 2) search left;
		if(count == 1) return root;
		if(count == 0) search right;

	> Bottom-Up

		node *L = LCA(left, p, q);
		node *R = LCA(right, p, q);
		if(L && R) return root;
		return L ? L : R;

3. Binary Tree with Parent Pointer

	> Hash
		Go up to root
	> Count Height
		h1 = height(p);
		h2 = height(q);
		assume h1 > h2:
			diff = h1 - h2;
			p go up "diff" dist
			p & q go up at the same pace until meet.
