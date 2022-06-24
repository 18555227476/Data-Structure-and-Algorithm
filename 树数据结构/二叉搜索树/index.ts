interface node{
    "left" : node|null,
    "value" : number,
    "right" : node|null,
};

class Tree{
    public add(value:number):boolean{
        if(this.root === null){
            this.root = {
                "left" : null,
                "value" : value,
                "right" : null,
            };
        }
        else{
            let pointer : node|null = this.root;
            let current : node = this.root;
            while(pointer !== null){
                current = pointer;
                if(current.value > value){
                    pointer = current.left;
                }
                else{
                    pointer = current.right;
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
    public del(value:number):boolean{
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
            let parent : node = this.root;
            let current : node|null = this.root;
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
                        parent.value > current.value ? (parent.left = null) : (parent.right = null);
                    }
                    else if(current.left !== null && current.right !== null){
                        let ParentNode : node = current;
                        let ChildNode : node = current.left;
                        while(ChildNode.right !== null){
                            ParentNode = ChildNode;
                            ChildNode = ChildNode.right;
                        };
                        ParentNode.value > ChildNode.value ? (ParentNode.left = ChildNode.left) : (ParentNode.right = ChildNode.left);
                        current.value = ChildNode.value;
                        console.log("execute");
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
                };
            };
            return false;
        };
    };
    public fontread():void{
        if(this.root != null){
            this.fontiterator(this.root);
        };
    };
    private root : node|null = null;
    private fontiterator(paramater:node|null):void{
        if(paramater !== null){
            console.log(paramater.value);
            this.fontiterator(paramater.left);
            this.fontiterator(paramater.right);
        };
    };
};

const tree:Tree = new Tree();
tree.add(11);
tree.add(7);
tree.add(15);
tree.add(5);
tree.add(9);
tree.add(13);
tree.add(20);
tree.add(3);
tree.add(6);
tree.add(8);
tree.add(10);
tree.add(12);
tree.add(14);
tree.add(18);
tree.add(25);
tree.del(7);
tree.fontread();