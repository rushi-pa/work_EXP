import { BrowserModule } from '@angular/platform-browser';
import { PostCardComponent } from './post-card/post-card.component';
import { SearchWidgetComponent } from './search-widget/search-widget.component';
import { LatestPostsComponent } from './latest-posts/latest-posts.component';
import { CategoriesComponent } from './categories/categories.component';
import { TagsComponent } from './tags/tags.component';
import { PostComponent } from './post/post.component';
import { PageNotFoundComponent } from './page-not-found/page-not-found.component';
import { PostDataComponent } from './post-data/post-data.component';
import { NgModule } from '@angular/core';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { FooterComponent } from './footer/footer.component';
import { HomeComponent } from './home/home.component';
import { BlogComponent } from './blog/blog.component';

@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    FooterComponent,
    HomeComponent,
    BlogComponent,
    PostComponent,
    PageNotFoundComponent,
    PostCardComponent,
    SearchWidgetComponent,
    LatestPostsComponent,
    CategoriesComponent,
    TagsComponent,
    PostDataComponent,
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
// why always forget export
// just why?

export class AppModule { }