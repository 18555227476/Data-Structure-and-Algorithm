interface Tree{
    value : string,
    children : Tree[],
}

const tree : Tree = {
    "value" : "a",
    "children" : [
        {
            "value" : "b",
            "children": [
                {
                    "value" : "e",
                    "children" : [],
                },
                {
                    "value" : "f",
                    "children" : [],
                },
                {
                    "value" : "g",
                    "children" : [],
                },
            ],
        },
        {
            "value" : "c",
            "children": [
                {
                    "value" : "h",
                    "children" : [],
                },
            ],
        },
        {
            "value" : "d",
            "children": [
                {
                    "value" : "i",
                    "children" : [],
                },
            ],
        },
    ],
};

const read1 = (tree:Tree):void=>{ //深度遍历
    console.log(tree.value);
    tree.children.forEach(read1);
};

const read2 = (tree:Tree):void=>{ //广度遍历
    const children : Tree[] = [tree];
    while(children.length){
        const element : Tree = children.shift() as Tree; 
        console.log(element.value);
        element.children.forEach((child) => {
            children.push(child);
        });
    };
};

read2(tree);