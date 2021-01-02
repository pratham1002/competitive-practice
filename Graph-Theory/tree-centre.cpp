/*
 * The centre is always the middle vertex,
 * or the middle two vertices in every
 * longest path along the tree.
 * 
 * Alternative approach:
 *  Iteratively pick off each leaf node layer
 *  like we were peeling an onion
 * 
 * Pseudo Code
 *  # g = tree represented as an undirected graph
 *  function treeCentres(g):
 *      n = g.numberOfNodes()
 *      degree = [0, ..., 0]    # size n
 *      leaves = []
 *      
 *      for (i = 0; i < n; i++):
 *          degree[i] = g[i].size()
 *          if degree[i] == 0 or degree[i] == 1:
 *              leaves.add(i)
 *              degree[i] = 0
 *          count = leaves.size()
 * 
 *      while count < n:
 *          new_leaves = []
 *          for (node: leaves)
 *              for (neighbor: g[node]):
 *                  degree[neighbor] = degree[neighbor] - 1
 *                  if degree[neighbor] == 1:
 *                      new_leaves.add(neighbor)
 *              degree[node] = 0
 *              count += new_leaves.size()
 *              leaves = new_leaves
 * 
 *     return leaves    # centres
 */