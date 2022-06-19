const tree = {
    "value" : "a",
    "children" : [
        {
            "value" : "b",
            "children" : [
                {
                    "value" : "e",
                    "children" : [
                        {
                            "value" : "i",
                            "children" : [],
                        },
                    ],
                },
                {
                    "value" : "f",
                    "children" : [],
                },
            ],
        },
        {
            "value" : "c",
            "children" : [
                {
                    "value" : "g",
                    "children" : [],
                },
                {
                    "value" : "h",
                    "children" : [],
                },
            ],
        },
        {
            "value" : "d",
            "children" : [],
        }
    ],
};

const read1 = (tree)=>{ //深度遍历
    console.log(tree.value);
    tree.children.forEach(read1);
};

const read2 = (tree)=>{ //广度遍历
    const children = [tree];
    while(children.length){
        const element = children.shift();
        console.log(element.value);
        element.children.forEach((child)=>{
            children.push(child);
        });
    };
};