//requiring path and fs modules
const path = require('path');
const fs = require('fs');
const Mustache = require('mustache');


const MUSTACHE_MAIN_DIR = './main.mustache';
const directoryPath = path.join(__dirname, 'leetcode');

var qn = [];
var diff = [];
var q =[];

function TitleCase(name){
    let nameCap='';
    let arr = name.split(" ");
    for(i=0;i<arr.length;i++){
        let word = arr[i];
        if(word =="i" || word=="ii"|| word=="iii"|| word=="iv"|| word=="v"|| word=="vi"|| word=="vii"|| word=="vii"|| word=="ix"|| word=="x"){
            word = word.toUpperCase();
        }
        else if(i==0 || !(word=='to' && word=='from'&& word=='of'&& word=='and'&& word=='the'&& word=='with'&& word=='in'&& word=='on')){
            word = arr[i].charAt(0).toUpperCase() + arr[i].slice(1);
        }
        nameCap+=word+' ';
    }
    return nameCap.slice(0,nameCap.length-1);
}
function MakeLink(name){
    let leetlink = 'https://leetcode.com/problems/'
    let arr = name.split(" ");
    let nameCap='';
    for(i=0;i<arr.length;i++){
        leetlink+=arr[i]+'-';
    }
    leetlink = leetlink.slice(0,leetlink.length-1)+'/'
    return '['+TitleCase(name)+']('+leetlink+')';
}

function cmp(a,b){
    return Number(a.split('_')[0]) < Number(b.split('_')[0]) ? -1:1;
}
function MakeDict2(){
    var prob=[];
    var no_e=0;
    var no_m=0;
    var no_h=0;
    files = fs.readdirSync(directoryPath);
    console.log('GETTING FILE NAMES');
    files.sort(cmp);
    files.forEach(function (file) {
        // file = file.slice(0,file.length-4);
            var f = file.split('.')[0].split('_');
            qn.push(f[0]);
            if(f[1]=='easy'){
                no_e +=1;
                diff.push('![Easy](https://img.shields.io/badge/Easy-green.svg)');
            }
            else if(f[1]=='med'){
                no_m +=1;
                diff.push('![Medium](https://img.shields.io/badge/Medium-orange.svg)');
            }
            else {
                no_h +=1;
                diff.push('![Hard](https://img.shields.io/badge/Hard-red.svg)');
            }
            var name ="";
            for(i=2;i<f.length;i++){
                name+=f[i]+" ";
            }
            q.push(MakeLink(name.slice(0,name.length-1)));
            // console.log(f[0],f[1],name);
    });
    for(i=0;i<qn.length;i++){
        prob.push(
            {
                qno: qn[i],
                diff: diff[i],
                qname: q[i],
            }
        );
    }
    return {
            prob: prob,
            num_e: no_e,
            num_m: no_m,
            num_h: no_h
            };
}

function generateReadMe() {
    console.log('MAKING README');
    fs.readFile(MUSTACHE_MAIN_DIR, (err, data) =>  {
        if (err) throw err;
        let obj_v = MakeDict2()
        console.log(obj_v)
        // var obj_v ={
        //     prob: v,
        //     num_e: num_e,
        //     num_m: num_m,
        //     num_h: num_h,
        // }
        const output = Mustache.render(data.toString(), obj_v);
        fs.writeFileSync('README.md', output);
    });
}
generateReadMe();
