class NodeTree {
    public value: number;
    public left?: NodeTree;
    public right?: NodeTree;

    constructor(value: number, right?: NodeTree, left?: NodeTree) {
        this.value = value;
        this.right = right;
        this.left = left;
    }

    public reverse() {
        const tmp = this.left;
        this.left = this.right;
        this.right = tmp;

        if(this.left) this.left.reverse();
        if(this.right) this.right.reverse();
    }
}

const tree_7 = new NodeTree(23);
const tree_6 = new NodeTree(9);
const tree_5 = new NodeTree(32);
const tree_4 = new NodeTree(6);
const tree_3 = new NodeTree(3, tree_6, tree_7);
const tree_2 = new NodeTree(2, tree_4, tree_5);
const tree_1 = new NodeTree(1, tree_2, tree_3);

tree_1.reverse();

console.log(tree_1);