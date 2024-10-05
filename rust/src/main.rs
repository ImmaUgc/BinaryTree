use std::mem::swap;

#[derive(Default, Debug)]
struct NodeTree {
    value: i32,
    left: Option<Box<NodeTree>>,
    right: Option<Box<NodeTree>>
}

impl NodeTree {
    fn reverse(&mut self) {
        swap(&mut self.right, &mut self.left);

        if let Some(left) = &mut self.left {
            left.reverse();
        }

        if let Some(right) = &mut self.right {
            right.reverse();
        }
    }
}

fn main() {
    let tree_5 = NodeTree {
        value: 8,
        ..Default::default()
    };

    let tree_4 = NodeTree {
        value: 6,
        ..Default::default()
    };

    let tree_3 = NodeTree {
        value: 2,
        left: Some(Box::new(tree_4)),
        right: Some(Box::new(tree_5))
    };

    let tree_2 = NodeTree {
        value: 3,
        ..Default::default()
    };

    let mut tree_1 = NodeTree {
        value: 1,
        left: Some(Box::new(tree_3)),
        right: Some(Box::new(tree_2))
    };

    tree_1.reverse();

    dbg!(tree_1);
}