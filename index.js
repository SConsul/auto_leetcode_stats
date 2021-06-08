//requiring path and fs modules
const path = require('path');
const fs = require('fs');
const Mustache = require('mustache');
const puppeteer = require('puppeteer')

const USERNAME = 'leetcode';
const MUSTACHE_MAIN_DIR = './main.mustache';
const directoryPath = path.join(__dirname, 'leetcode');

var qn = [];
var diff = [];
var q =[];

function TitleCase(name){
    let nameCap='';
    let arr = name.split("-");
    for(i=0;i<arr.length;i++){
        let word = arr[i];
        if(word =="i" || word=="ii"|| word=="iii"|| word=="iv"|| word=="v"|| word=="vi"|| word=="vii"|| word=="vii"|| word=="ix"|| word=="x"){
            word = word.toUpperCase();
        }
        else if(i==0 || !(word=='to' || word=='from' || word=='of'|| word=='and'|| word=='the'|| word=='with'|| word=='in'|| word=='on'|| word=='is'||word=='by'|| word=='a')){
            word = arr[i].charAt(0).toUpperCase() + arr[i].slice(1);
        }
        nameCap+=word+' ';
    }
    return nameCap.slice(0,nameCap.length-1);
}
function MakeLink(name){
    let leetlink = 'https://leetcode.com/problems/'
    leetlink += name+'/'
    console.log(TitleCase(name));
    return '['+TitleCase(name)+']('+leetlink+')';
}

function cmp(a,b){
    return Number(a.split('_')[0]) < Number(b.split('_')[0]) ? -1:1;
}
function generateReadMe(){
    console.log('MAKING README');
    fs.readFile(MUSTACHE_MAIN_DIR, (err, data) =>  {
        if (err) throw err;

        console.log('MAKING DICT');
        async function  webscrape(){
            console.log('WEBSCRAPING');
            const browser = await puppeteer.launch({
                headless: true,
                args: [
                    "--no-sandbox",
                    "--disable-setuid-sandbox"
                ],
            });
            const page = await browser.newPage();
            let leetURL = `https://leetcode.com/${USERNAME}`;
            console.log(leetURL);
            await page.goto(leetURL);
            await page.waitForFunction('document.querySelector("body").innerText.includes("Easy")');
            let ts = await page.evaluate(() => {
                let data = [];
                let elements = document.getElementsByClassName('difficulty-total-count__y_em');
                for (var element of elements)
                    data.push(element.textContent);
                return data;
            });
            console.log(ts);
            await browser.close();
            return ts;
        };
        webscrape().then((tots) =>{
            var prob=[];
            var no_e=0;
            var no_m=0;
            var no_h=0;
            var no_total=0;
            files = fs.readdirSync(directoryPath);
            console.log('GETTING FILE NAMES');
            files.sort(cmp);
            files.forEach(function (file) {
                var f = file.split('.')[0].split('_');
                qn.push(f[0]);
                if(f[1].charAt(0)=='e'||f[1].charAt(0)=='E'){
                    no_e +=1;
                    no_total+=1;
                    diff.push('![Easy](https://img.shields.io/badge/Easy-43A047.svg)');
                }
                else if(f[1].charAt(0)=='m'||f[1].charAt(0)=='M'){
                    no_m +=1;
                    no_total+=1;
                    diff.push('![Medium](https://img.shields.io/badge/Medium-FB8C00.svg)');
                }
                else if(f[1].charAt(0)=='h'||f[1].charAt(0)=='H'){
                    no_h +=1;
                    no_total+=1;
                    diff.push('![Hard](https://img.shields.io/badge/Hard-E91E62.svg)');
                }
                q.push(MakeLink(f[2]));
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
            let obj_v = {
                prob: prob,
                num_e: no_e,
                num_m: no_m,
                num_h: no_h,
                num_total: no_total,
                total_e: tots[0],
                total_m: tots[1],
                total_h: tots[2]
            };
            const output = Mustache.render(data.toString(), obj_v);
            fs.writeFileSync('README.md', output);
        });
    });
}

generateReadMe();
