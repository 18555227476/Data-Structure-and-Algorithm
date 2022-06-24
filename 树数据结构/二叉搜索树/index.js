class Tree{
    constructor(){
        this.root = null;
    };
    add(value){
        if(this.root === null){
            this.root = {
                "left" : null,
                "value" : value,
                "right" : null,
            };
        }
        else{
            let current = this.root;
            let pointer = this.root;
            while(pointer != null){
                current = pointer;
                if(current.value > value){
                    pointer = current.left;
                }
                else if(current.value < value){
                    pointer = current.right;
                }
                else{
                    return false;
                };
            };
            if(current.value > value){
                current.left = {
                    "left" : null,
                    "value" : value,
                    "right" : null,
                };
            }
            else{
                current.right = {
                    "left" : null,
                    "value" : value,
                    "right" : null,
                };
            };
        };
        return true;
    };

    del(value){
        if(this.root === null){
            return false;
        }
        else if(this.root.left === null && this.root.right === null){
            if(this.root.value === value){
                this.root = null;
                return true;
            }
            else{
                return false;
            };
        }
        else{
            let current = this.root;
            let parent = this.root;
            while(current !== null){
                if(current.value > value){
                    parent = current;
                    current = current.left;
                }
                else if(current.value < value){
                    parent = current;
                    current = current.right;
                }
                else{
                    if(current.left === null && current.right === null){
                        parent.value > current.value ? (parent.left = null) : parent.right = null;
                    }
                    else if(current.left !== null && current.left !== null){
                        let parentNode = current;
                        let childNode = current.left;
                        while(childNode.right !== null){
                            parentNode = childNode;
                            childNode = childNode.right;
                        };
                        parentNode.value > childNode.value ? (parentNode.left = childNode.left) : (parentNode.right = childNode.left);
                        current.value = childNode.value;
                    }
                    else{
                        if(current.left === null){
                            parent.value > current.value ? (parent.left = current.right) : (parent.right = current.right);
                        }
                        else{
                            parent.value > current.value ? (parent.left = current.left) : (parent.right = current.left); 
                        };
                    };
                    return true;
                }
            };
            return false;
        };
    };

    fontread(){
        if(this.root != null){
            this.fontiterator(this.root);
        }
    };

    fontiterator(element){
        if(element != null){
            console.log(element.value);
            this.fontiterator(element.left);
            this.fontiterator(element.right);
        };
    };
};

const tree = new Tree();
tree.add(11);
tree.add(6);
tree.add(15);
//tree.add(5);
tree.add(9);
tree.add(13);
tree.add(20);
tree.add(6);
tree.add(3);
tree.add(8);
tree.add(10);
tree.add(12);
tree.add(14);
tree.add(18);
tree.add(25);
//tree.del(6);
tree.fontread();
