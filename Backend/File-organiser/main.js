//  node main.js organize "C:\Users\HP\Downloads"
// node main.js tree "path"
let inputArr = process.argv.slice(2);
let fs = require("fs");
let path = require("path");
 console.log(inputArr);
 // node main.js tree "directoryPath"
 // node main.js organize "directoryPath"
 // node main.js help
let command = inputArr[0];
let types = {
	   media: ["mp4", "mkv", 'NEF'],
	   archives: ['zip', '7z', 'rar', 'tar','rar', 'gz', 'ar', 'iso', "xz"],
	   documents: ["docx", 'doc', 'pdf', 'xlsx', 'xls', 'odt', 'ods', 'odp', 'odg', 'odf', 'txt', 'ps', 'tex'],
	   app: ['exe', 'dmg', 'pkg', "deb"]
}

switch(command){
	case "tree":
		treeFn(inputArr[1]);
		break;
	case "organize":
		organizeFn(inputArr[1]);
		break;
	case "help":
		helpFn()
		break;
	default:
		console.log("Please input right command");
			break;	
}

function treeFn(dirPath){
	console.log("Tree command implementation for", dirPath);
	// let destPath;
	if(dirPath == undefined){
		console.log("Kindly enter the path");
		return;
	}else{
    //	Now let's check whether any path exist or not
		let doesExist = fs.existsSync(dirPath);
		if(doesExist){
			treeHelper(dirPath, "");	
		}else{
			console.log("Kindly enter the correct path");
			return;
		}
	}
}

function treeHelper(dirPath, indent){
	let isFile = fs.lstatSync(dirPath).isFile();
	if(isFile==true){
		let fileName = path.basename(dirPath);
		console.log(indent + "⊢→→→→>" + fileName);
	}else{
		let dirName = path.basename(dirPath);
		console.log(indent + "⊢➖⋙⋙ " + dirName);
		let childrens = fs.readdirSync(dirPath);
		for(let i=0; i<childrens.length; i++){
			let childPath = path.join(dirPath, childrens[i]);
			treeHelper(childPath, indent + "\t");
		}
	} 
}

function organizeFn(dirPath){
	// console.log("Organize command implementation for", dirPath);
// 1.input -> directory path given
	let destPath;
	if(dirPath == undefined){
		console.log("Kindly enter the paht");
		return;
	}else{
    //	Now let's check whether any path exist or not
		let doesExist = fs.existsSync(dirPath);
		if(doesExist){
			// now let's organised
// 2. create->organized_files->directory
			destPath = path.join(dirPath, "organized_files");
			// edge case if files already exist then don't need to make a new one
			if(fs.existsSync(destPath)==false){
				fs.mkdirSync(destPath);
			}
			// fs.mkdirSync(destPath);		
		}else{
			console.log("Kindly enter the correct path");
			return;
		}
	}
	
	organizeHelper(dirPath, destPath);

	function organizeHelper(src, dest){
	// 3. identify categories of all the files present in that input directory ->
		let childNames = fs.readdirSync(src);
		//  console.log(childNames);

		for(let i=0; i<childNames.length; i++){
			let childAddress = path.join(src, childNames[i]);
			let isFile = fs.lstatSync(childAddress).isFile();
			if(isFile){
				// console.log(childNames[i]);
				// 4. copy/cut files to that organized directory inside of any of category folder
				let Category = getCategory(childNames[i]); 
				console.log(childNames[i], "category belongs to -->", Category);
				sendFiles(childAddress, dest, Category);
			}
		}
	}
	

}
function helpFn(){
	console.log(
		`List of All commands:
				node main.js tree "directoryPath"
 				node main.js organize "directoryPath"
 				node main.js help
				`);
}

function getCategory(name){
	let ext = path.extname(name);
	ext = ext.slice(1); // remove the dot from extension
	for(let type in types){
		let cTypeArray = types[type];
		for(let i=0; i<cTypeArray.length; i++){
			if(ext==cTypeArray[i]){
				return type;
			}
		}
	}
	return "others";
	
}

function sendFiles(srcFilePath, dest, Category){
	let categoryPath = path.join(dest, Category);
	if(fs.existsSync(categoryPath) == false){
		fs.mkdirSync(categoryPath);
	}
	let fileName = path.basename(srcFilePath);
	let destFilePath = path.join(categoryPath, fileName);
	fs.unlinkSync(srcFilePath);
	fs.copyFileSync(srcFilePath, destFilePath);
	console.log(fileName, " copied to: ", Category);
}
