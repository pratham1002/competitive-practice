/*
 * Creating a rooted tree from a tree with undirected edges
 * 
 * Pseudo code
 *  # TreeNode object structure
 *  class TreeNode:
 *      # Unique integer id to identify this node.
 *      int id;
 *      
 *      # Pointer to parent TreeNode reference.
 *      # Onle the root node has null parent TreeNode reference.
 *      TreeNode parent;
 * 
 *      # List of pointers to child TreeNode(s)
 *      TreeNode[] children; 
 * 
 *  # g = undirected graph / tree represented as adjacency list.
 *  function rootTree(g, rootId = 0):
 *      root = TreeNode(rootId, null, [])
 *      return buildTree(g, root, null)
 * 
 *  # Build tree recursively depth first.
 *  function buildTree(g, node, parent):
 *      for childId in g[node.id]:
 *          # Avoid adding an edge pointing back to the parent.
 *          if parent != null and childId == parent.id:
 *              continue
 *          child = TreeNode(childId, node, [])
 *          node.children.add(child)
 *          buildTree(g, child, node)
 *      return node
 */