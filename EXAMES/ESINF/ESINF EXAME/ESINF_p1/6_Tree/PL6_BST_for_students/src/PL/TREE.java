package PL;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/*
 * @author DEI-ESINF
 * @param <E>
 */
public class TREE<E extends Comparable<E>> extends BST<E> {

    /*
   * @param element A valid element within the tree
   * @return true if the element exists in tree false otherwise
     */
    public boolean contains(E element) {
        Node<E> test = find(element, root());
        return test != null;
    }

    public boolean isLeaf(E element) {
        Node<E> test = find(element, root());
        if (test == null) {
            return false;
        }
        return test.getLeft() == null && test.getRight() == null;

    }

    /*
   * build a list with all elements of the tree. The elements in the 
   * left subtree in ascending order and the elements in the right subtree 
   * in descending order. 
   *
   * @return    returns a list with the elements of the left subtree 
   * in ascending order and the elements in the right subtree is descending order.
     */
    public Iterable<E> ascdes() {
        List<E> snapshot = new ArrayList<>();
        if (root() != null) {
            ascSubtree(root().getLeft(), snapshot);
            snapshot.add(root().getElement());
            desSubtree(root().getRight(), snapshot);
        }
        return snapshot;
    }

    private void ascSubtree(Node<E> node, List<E> snapshot) {
        if (node == null) {
            return;
        }
        ascSubtree(node.getLeft(), snapshot);
        snapshot.add(node.getElement());
        ascSubtree(node.getRight(), snapshot);
    }

    private void desSubtree(Node<E> node, List<E> snapshot) {
        if (node == null) {
            return;
        }
        desSubtree(node.getRight(), snapshot);
        snapshot.add(node.getElement());
        desSubtree(node.getLeft(), snapshot);
    }

    /**
     * Returns the tree without leaves.
     *
     * @return tree without leaves
     */
    public BST<E> autumnTree() {
        BST<E> tree = new TREE();
        tree.root = copyRec(root());
        return tree;
    }

    private Node<E> copyRec(Node<E> node) {
        if (node == null) {
            return null;
        }
        if (node.getLeft() != null || node.getRight() != null) {
            return new Node(node.getElement(), copyRec(node.getLeft()), copyRec(node.getRight()));
        }
        return null;
    }

    /**
     * @return the the number of nodes by level.
     */
    public int[] numNodesByLevel() {
        int[] result = new int[height() + 1];
        numNodesByLevel(root(), result, 0);
        return result;
    }

    private void numNodesByLevel(Node<E> node, int[] result, int level) {
        if (node == null) {
            return;
        }
        result[level]++;
        numNodesByLevel(node.getLeft(), result, level + 1);
        numNodesByLevel(node.getRight(), result, level + 1);
    }

    public LinkedList<Node<E>> base_arvore() {
        LinkedList<Node<E>> result = new LinkedList<>();
        base_arvore(root, 0, result);
        return result;
    }

    private void base_arvore(Node<E> node, int level, LinkedList<Node<E>> result) {

        if (node == null) {
            return;
        }
        if (level == this.height()) {
            result.add(node);
        } else if (level < this.height()) {
            base_arvore(node.getLeft(), level++, result);
            base_arvore(node.getRight(), level++, result);
        }
    }

}
