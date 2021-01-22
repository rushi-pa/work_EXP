import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { BlogComponent } from './blog/blog.component';
import { HomeComponent } from './home/home.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { PostComponent } from './post/post.component';
// path dosent open on front page
const routes: Routes = [
  { path: 'home', component: HomeComponent },//not working
  { path: 'blog', component: BlogComponent },// working
  { path: 'post', component: PostComponent },//woring
  { path: '', redirectTo: '/home', pathMatch: "full" },
  { path: '**', component: PageNotFoundComponent },
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
// forgot to export lol
export class AppRoutingModule { }