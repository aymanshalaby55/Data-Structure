# what is trie ?

- a tire is a data strucure which is used to sort dynamic set of strings.
- in general it's m-array tree where edge has a letter.
- in letter tree a word of N letters spans N nodes.
  ![Trie](../public/trie.png)
- colored nodes means that it's end of a word.
- now you can iterate in O(n)
> It's important to note that while tries are efficient, there are other data structures that can be more suitable for certain tasks, such as suffix arrays and suffix trees.

# impelementation :
### how can we build data structure like that ?
- as we have 26 letter of english, then every node must have 26 child.
- and when iserting or searching a letter we must look if there exsist a child of the with the order of the letter if the alphabet order.
> letter - 'a' -> index of the letter.
